# Loosely-coupled design

- Create a fake object to a separate class using Dependency Injection

![[Pasted image 20231231165254.png]]


## Programming against interfaces / Using Dependency Injection

```csharp
public interface IFileReader
{
	string Read(string path);
}

// Implementation
public class FileReader : IFileReader
{
	public string Read(string path)
	{
		return File.ReadAllText();
	}
}
```

## DI via method parameters vs. via properties vs. via constructors

### Via parameters

```csharp
// Via method parameters
public class VideoService()
{
	public string ReadVideoTitle(IFileReader fileReader)
	{
		// Implementation
	}
}
[Test]
public void ReadVideoTitle_EmptyTitle_ReturnError()
{
	var service = new VideoService();
	var result = service.ReadVideoTitle(new FakeFileReader());
	Assert.That(result, Does.Contain("error").IgnoreCase);
}
```

### Via properties

```csharp
public class VideoService()
{
	public IFileReader FileReader { get; set; }
	public string ReadVideoTitle()
	{
		FileReader = new FileReader();
	}
	// Implementation
}
[Test]
public void ReadVideoTitle_EmptyTitle_ReturnError()
{
	var service = new VideoService();
	// Replace the real FileReader with a mocked one
	service.FileReader = new FakeFileReader();
	var result = service.ReadVideoTitle();
	Assert.That(result, Does.Contain("error").IgnoreCase);
}
```

### Via constructor

```csharp
public class VideoService()
{
	private IFileReader _fileReader;
	public string ReadVideoTitle(IFileReader fileReader = null)
	{
		_fileReader = fileReader ?? new FileReader();
	}
	// Implementation
}
[Test]
public void ReadVideoTitle_EmptyTitle_ReturnError()
{
	var service = new VideoService(new FakeFileReader());
	var result = service.ReadVideoTitle();
	Assert.That(result, Does.Contain("error").IgnoreCase);
}
```

# State-based vs Interaction testing

- State-based: Test how the state of a variable changes

```cs
var result = myObj.ReturnValue();

Assert.That(result, Is.EqualTo(...))
```

- Interaction: Test interaction between classes

```cs
public class OrderService
{
	public void PlaceOrder(Order order)
	{
		// Test the interactions between OrderService class and Order class
		_storage.Store(order);
	}
}
```

> [!important]
> 
> - Use interaction testing only when dealing with **external resources**
> - Use mocks **as little as possible**, only reserve them when dealing with **external resources**
> - Unit + Integration testing are for developers, E2E is for testers


---

# Exercises

## Testing a service

```cs
// Setup for mocking a service
public class VideoService
{
	private readonly IFileReader _fileReader;
	private readonly IVideoRepository _videoRepository;
	public VideoService(IFileReader fileReader, IVideoRepository videoRepository)
	{
		_fileReader = fileReader;
		_videoRepository = videoRepository;
	}
	public string ReadVideoTitle()
	{
		var str = _fileReader.Read("video.txt");
		var video = JsonConvert.DeserializeObject<Video>(str);
		if (video == null)
			return "Error parsing the video.";
		return video.Title;
	}
}
[TestFixture]
public class TestVideoService
{
	[SetUp]
	public void SetUp()
	{
		_mockFileReader = new Mock<IFileReader>();
		_mockRepository = new Mock<IVideoRepository>();
		_mockVideoService = new VideoService(_mockFileReader.Object, _mockRepository.Object);
	}
	
	[Test]
	public void ReadVideoTitle_EmptyFile_ReturnError()
	{
		// ARRANGE
		_mockFileReader.Setup(fr => fr.Read("video.txt")).Returns("")
		// ACT
		var result = _mockVideoService.ReadVideoTitle();
		// ASSERT
		Assert.That(result, Does.Contain("error").IgnoreCase)
	}
}

```

## Testing a helper method

```cs
// Program against interfaces
public interface IFileDownloaded
{
	void DownloadFile(string url, string path);
}
public class FileDownloader : IFileDownloader
{
	public void DownloadFile(string url, string path)
	{
		var client = new WebClient();
		client.DownloadFile(url, path);
	}
}
// Helper
public class InstallerHelper
{
	private string _setupDestinationFile;
	private readonly IFileDownloader _fileDownloader;
	public InstallerHelper(IFileDownloader fileDownloader)
	{
		_fileDownloader = fileDownloader;
	}

	public bool DownloadInstaller(string customerName, string installerName)
	{
		try
		{
			_fileDownloader.DownloadFile(
			string.Format("http://example.com/{0}/{1}",
			customerName,
			installerName), _setupDestinationFile);
			return true;
		}
		catch (WebException)
		{
			return false;
		}
	}
}

// Testing the helper
[TestFixture]
public class TestInstallerHelper
{
	private Mock<IFileDownloader> _mockFileDownloader;
	private InstallerHelper _mockInstallerHelper;
	[SetUp]
	public void Setup()
	{
		_mockFileDownloader = new Mock<IFileDownloader>();
		_mockInstallerHelper = new InstallerHelper(_mockFileDownloader.Object);
	}
	[Test]
	public void DownloadInstaller_DownloadFails_ReturnFalse()
	{
		// ARRANGE
		// Use It.IsAny to make the test more generic
		_mockFileDownloader.Seup(fd => fd.DownloadFile(It.IsAny<string>(), It.IsAny<string>())).Throws<WebException>();
		// ACT
		var result = _mockInstallerHelper.DownloadInstaller("customer", "installer");
		// ASSERT
		Assert.That(result, Is.False)
	}
	[Test]
	public void DownloadInstaller_DownloadCompletes_ReturnTrue()
	{
		// ACT
		var result = _mockInstallerHelper.DownloadInstaller("customer", "installer");
		// ASSERT
		Assert.That(result, Is.False)
	}
}
```

## Testing a controller method

```cs
// Layer similar to Service layer
public interface IEmployeeStorage
{
	void DeleteEmployee(int id);
}
public class EmployeeStorage : IEmployeeStorage
{
	private EmployeeContext _db;
	public EmployeeStorage()
	{
		_db = new EmployeeContext();
	}
	public void DeleteEmployee(int id)
	{
		var employee = _db.Employees.Find(id);
		_db.Employees.Remove(employee);
		_db.SaveChanges();
	}
}
public class EmployeeController
{
	private IEmployeeStorage _employeeStorage;
	public EmployeeController(IEmployeeStorage employeeStorage)
	{
		_employeeStorage = employeeStorage;
	}
	public ActionResult DeleteEmployee(int id)
	{
		_employeeStorage.DeleteEmployee(id);
		return RedirectToAction("Employees")';
	}
	private ActionResult RedirectToAction(string employees)
	{
		return new RedirectResult();
	}
}
// Test
[TestFixture]
public class TestEmployeeController
{
	[Test]
	public void DeleteEmployee_WhenCalled_DeleteTheEmployeeFromDb()
	{
		// ARRANGE
		var mockEmployeeStorage = new Mock<IEmployeeStorage>();
		var mockEmployeeController = new EmployeeController(mockEmployeeStorage.Object);
		// ACT
		mockEmployeeController.DeleteEmployee(1);
		// ASSERT
		mockEmployeeStorage.Verify(s => s.DeleteEmployee(1));
	}
}
```

