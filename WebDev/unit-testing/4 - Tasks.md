# Test a function that check overlapping periods

```cs
public class UnitOfWork
{
	public IQueryable<Booking> Query<T>()
	{
		return new List<Booking>().AsQueryable();
	}
}

public class Booking
{
	public int Id { get; set; }
	public string Status { get; set; }
	public DateTime ArrivalDate { get; set; }
	public DateTime DepartureDate { get; set; }
	public string Reference { get; set; }

}

public interface IBookingRepository
{
	IQueryable<Booking> GetActiveBookings(int? excludeBookingId = null);
}

public class BookingRepository : IBookingRepository
{
	public IQueryable<Booking> GetActiveBookings(int? excludeBookingId = null)
	{
		var unitOfWork = new UnitOfWork();
		var bookings = 
			unitOfWork.Query<Booking>()
				.Where(
					b => b.Status  != "Cancelled");
		if (excludeBookingId.HasValue)
		{
			bookings = bookings.Where(b => b.Id != excludeBookingId.Value);
		}
		return bookings;
	}
}
// For static class, using parameters for DI (Supposed that parameter injeciton is supported here)
public static class BookingHelper
{
	public static string GetOverlappingBookingIfExist(Booking booking, IBookingRepository repository)
	{
		if (booking.Status  == "Canceled")
			return string.Empty;
		var bookings = repository.GetActiveBookings(booking.Id);
		// Algorithm to detect overlapping period
		// bool overlap = tStartA < tEndB && tStartB < tEndA
		var overlappingBooking = 
			bookings.FirstOrDefault(
				b =>
					booking.ArrivalDate < b.DepartureDate
					&& booking.DepartureDate > b.ArrivalDate);
		return overlappingBooking == null ? string.empty : overlappingBooking.Reference;
	}
}
[TestFixture]
public class TestBookingHelper_TestOverlappingBookingExists
{
	private Booking _mockExistingBooking;
	private Mock<IBookingRepository> _mockRepository;
	
	[SetUp]
	public void SetUp()
	{
		// ARRANGE
		_mockBooking = new Booking
		{
			Id = 2,
			ArrivalDate = ArriveOn(2017, 1, 15),
			DepartureDate = DepartOn(2017, 1, 20),
			Reference = "a",
		};
		_mockRepository = new Mock<IBookingRepository>();

		_mockRepository.Setup(r => r.GetActiveBookings(1)).Returns(new List<Booking>
		{
			_mockExistingBooking
		}.AsQueryable());
	}
	
	// 1st test
	[Test]
	public void GetOverlappingBookingIfExist_BookingStartsAndFinishesBeforeAnExistingBooking_ReturnEmptyString()
	{
		// ACT
		var result = BookingHelper.GetOverlappingBookingIfExist(new Booking
			{
				Id = 1,
				ArrivalDate = Before(_mockExistingBooking.ArrivalDate, days: 2),
				DepartureDate = Before(_mockExistingBooking.ArrivalDate),
			}, _mockRepository.Object);
			
		// ASSERT
		Assert.That(result, Is.Empty); // PASS
	}
	
	// 2nd test
	[Test]
	public void GetOverlappingBookingIfExist_BookingStartsAndFinishesInTheMiddleOfAnExistingBooking_ReturnExistingBookingReference()
	{
		// ACT
		var result = BookingHelper.GetOverlappingBookingIfExist(new Booking
			{
				Id = 1,
				ArrivalDate = After(_mockExistingBooking.ArrivalDate),
				DepartureDate = Before(_mockExistingBooking.DepartureDate),
			}, _mockRepository.Object);
			
		// ASSERT
		Assert.That(result, Is.EqualTo(_mockExistingBooking.Reference)); // PASS
	}
	
	// 3rd test
	[Test]
	public void GetOverlappingBookingIfExist_BookingStartsAndFinishesAfterAnExistingBooking_ReturnEmptyString()
	{
		// ACT
		var result = BookingHelper.GetOverlappingBookingIfExist(new Booking
			{
				Id = 1,
				ArrivalDate = After(_mockExistingBooking.DepartureDate),
				DepartureDate = After(_mockExistingBooking.DepartureDate, days: 2),
			}, _mockRepository.Object);
			
		// ASSERT
		Assert.That(result, Is.Empty); // PASS
	}
	
	// 4th test
	[Test]
	public void GetOverlappingBookingIfExist_BookingStartsBeforeAndFinishesInTheMiddleOfAnExistingBooking_ReturnExistingBookingReference()
	{
		// ACT
		var result = BookingHelper.GetOverlappingBookingIfExist(new Booking
			{
				Id = 1,
				ArrivalDate = Before(_mockExistingBooking.ArrivalDate),
				DepartureDate = Before(_mockExistingBooking.DepartureDate),
			}, _mockRepository.Object);
			
		// ASSERT
		Assert.That(result, Is.EqualTo(_mockExistingBooking.Reference)); // PASS
	}
	
	// 5th test
	[Test]
	public void GetOverlappingBookingIfExist_BookingStartsIn TheMiddleOfAndFinishesAfterAnExistingBooking_ReturnExistingBookingReference()
	{
		// ACT
		var result = BookingHelper.GetOverlappingBookingIfExist(new Booking
			{
				Id = 1,
				ArrivalDate = After(_mockExistingBooking.ArrivalDate),
				DepartureDate = After(_mockExistingBooking.DepartureDate),
			}, _mockRepository.Object);
			
		// ASSERT
		Assert.That(result, Is.EqualTo(_mockExistingBooking.Reference)); // PASS
	}
	
	// 6th test
	[Test]
	public void GetOverlappingBookingIfExist_BookingStartsbeforeAndFinishesAfterAnExistingBooking_ReturnExistingBookingReference()
	{
		// ACT
		var result = BookingHelper.GetOverlappingBookingIfExist(new Booking
			{
				Id = 1,
				ArrivalDate = Before(_mockExistingBooking.ArrivalDate),
				DepartureDate = After(_mockExistingBooking.DepartureDate),
			}, _mockRepository.Object);
			
		// ASSERT
		Assert.That(result, Is.EqualTo(_mockExistingBooking.Reference)); // PASS
	}
	
	// 7th test
	[Test]
	public void GetOverlappingBookingIfExist_BookingOverlapsButNewBookingCancelled_ReturnEmptyString()
	{
		// ACT
		var result = BookingHelper.GetOverlappingBookingIfExist(new Booking
			{
				Id = 1,
				ArrivalDate = Before(_mockExistingBooking.ArrivalDate),
				DepartureDate = After(_mockExistingBooking.DepartureDate),
				Status = "Cancelled"
			}, _mockRepository.Object);
			
		// ASSERT
		Assert.That(result, Is.Empty); // PASS
	}
	
	// Helpers
	private DateTime Before(DateTime dateTime, int days = 1)
	{
		return dateTime.AddDays(-days);
	}
	
	private DateTime After(DateTime dateTime, int days = 1)
	{
		return dateTime.AddDays(days);
	}
	
	// Refactoring for cleaner tests
	private DateTime ArriveOn(int year, int month, int day)
	{
		return new DateTime(year, month, day, 14, 0, 0);
	}
	
	private DateTime DepartOn(int year, int month, int day)
	{
		return new DateTime(year, month, day, 10, 0, 0);
	}
}
```

# Test `SendStatementEmails`


```csharp
// Extracting the interface
public interface IUnitOfWork
{
	IQueryable<T> Query<T>();
}

public class UnitOfWork : IUnitOfWork
{
	public IQueryable<T> Query<T>()
	{
		return new List<T>().AsQueryable();
	}
}

// Additional classes for external dependencies
public interface IStatementGenerator
{
	string SaveStatement(int houseKeeperOid, string houseKeeperName, DateTime statementDate);
}
public class StatementGenerator : IStatementGenerator
{
	public string SaveStatement(int houseKeeperOid, string houseKeeperName, DateTime statementDate)
	{
		var report = new HouseKeeperStatementReport(houseKeeperOid, statementDate);
		
		if (!report.HasData)
		{
			return string.Empty;
		}
		report.CreateDocument();
		
		var fileName = Path.Combine(
			Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments),
			string.Format("Sandpiper Statement {0:yyyy-MM} {1}.pdf", statementDate, houseKeeperName));
			
		report.ExportToPdf(fileName);
		
		return fileName;
	}
}

public class EmailSender
{

}

// Helper to test
public class HouseKeeperHelper
{
	private readonly UnitOfWork _unitOfWork;
	private readonly IStatementGenerator _statementGenerator;
	
	public HouseKeeperHelper(IUnitOfWork unitOfWork, IStatementGenerator statementGenerator)
	{
		_unitOfWork = unitOfWork;
		_statementGenerator = statementGenerator;
	}
	
	public bool SendStatementEmails(DateTime statementDate)
	{
		var houseKeepers = _unitOfWork.Query<HouseKeeper>();
		
		foreach (var houseKeeper in houseKeepers)
		{
			if (houseKeeper.Email == null)
			{
				continue;
			}
			var statementFileName = _statementGenerator.SaveStatement(houseKeeper.Oid, houseKeeper.FullName, statementDate);
			if (string.IsNullOrWhiteSpace(statementFileName))
			{
				continue;
			}
			var emailAddress = houseKeeper.Email;
			var emailBody = houseKeeper.StatementEmailBody;
		}
	}
}
```