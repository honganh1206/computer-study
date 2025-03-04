
## Testing strings

```cs

// Method to be tested
public string FormatAsBold(string content)
{
	return $"<strong>{content}</strong>";
}

// Testing methods
[Test]
public void FormatAsBold_WhenCalled_ShouldEncloseStringWithStrongElement()
{
	// Arrange
	var formatter = new HtmlFormatter();

	var result = formatter.FormatAsBold("abc")
	// Assert
	// Specific
	Assert.That(result, Is.EqualTo("<strong>abc</strong>"));

	// More general
	Assert.That(result, Does.StartWith("<strong>"));
	Assert.That(result, Does.StartWith("</strong>"))
}

```

## Testing arrays and collections

```csharp
// Method to be tested
public IEnumerable<int> GetOddNumbers(int limit)
{
	for (int i = 0; i < limit; i++)
	{
		if (i % 2 != 0)
		{
			yield return i;
		}
	}
}
[Test]
public void GetOddNumbers_LimitIsGreaterThanZero_ReturnOddNumbersUpToLimit()
{
	// Arrange + Act
	var result = _math.GetOddNumbers(5);
	// Assert
	// General
	Assert.That(result, Is.Not.Empty);
	// Specific
	Assert.That(result.Count(), Is.EqualTo(3));
	Assert.That(result, Is.EquivalentTo(new[] {1,3,5}));
	Assert.That(result, Is.Ordered);
	Assert.That(result, Is.Unique)
}
// Testing methods

```

## Testing return type of methods

```cs
public class TestController
{
	public ActionResult GetCustomer(int id)
	{
		if (id == 0)
		{
			return new NotFound();
		}
		return new Ok();
	}
}

public class ActionResult {}
public class NotFound : ActionResult {}
public class Ok : ActionResult {}

[TestFixture]
public class TestControllerTests
{
	[Test]
	public void GetCustomer_IdIsZero_ReturnNotFound()
	{
		var controller = new TestController();

		var result = controller.GetCustomer(0);
	
		// NotFound
		Assert.That(result, Is.TypeOf<NotFound>());
		// NotFound or one of its deriatives
		Assert.That(result, Is.InstanceOf<NotFound>());
	}

	[Test]
	public void GetCustomer_IdNotZero_ReturnOk()
	{
		
	}
}

```


## Testing void methods + exceptions + methods that raise events

```cs
public class ErrorLogger
{
	public string LastError { get; set; }
	public event EventHandler<Guid> ErrorLogged;

	public void Log(string error)
	{
		if (string.IsNullOrWhiteSpace(error))
		{
			throw new ArgumentNullException();
		}

		LastError = error;

		// Write the log to the storage
		// ...

		// Raise the error
		ErrorLogged.Invoke(this, Guid.NewGuid());
	}

}

[Test]
public void Log_WhenCalled_SetLastErrorProperty
{
	var logger = new ErrorLogger();
	logger.Log("AAA");

	Assert.That(logger.LastError, Is.EqualTo("AAA"));
}

[Test]
[TestCase(null)]
[TestCase("")]
[TestCase(" ")]
public void Log_InvalidError_ThrowArgumentNullException(string error)
{
	var logger = new ErrorLogger();

	Assert.That(() => logger.Log(error), Throws.ArgumentNullException);

}


[Test]
public void Log_ValidError_RaiseErrorLoggedEvent
{
	var logger = new ErrorLogger();

	var id = Guid.Empty;

	// Get a new Guid for every event raise
	logger.ErrorLogged += (sender, args) => { id = args };

	logger.Log("AAA");

	Assert.That(id, Is.Not.EqualTo(Guid.Empty));
}
```


```ad-warning
You should NOT test private/protected methods, as they involve implementation detail that slows down your testing/development

```

## Code coverage

- % of code tested
- Fine Code Coverage for VS

---

# Exercises

## Calculating demerit points

```csharp
// Method to test
public class DemeritPointsCalculator
{
	private const int SpeedLimit = 65;
	private const int MaxSpeed = 300;

	public int CalculateDemeritPoints(int speed)
	{
		if (speed == null)
		{
			throw new ArgumentNullException();
		}
		
		if (speed < 0 || speed > MaxSpeed)
		{
			throw new ArgumentOutOfRangeException();
		}

		if (speed <= SpeedLimit)
		{
			return 0;
		}

		const int kmPerDemeritPoint = 5;
		var demeritPoints = (speed - SpeedLimit)/kmPerDemeritPoint;

		return demeritPoints;
	}
}

// Test methods
[TestFixture]
public class DemeritPointsCalculatorTests
{
	[Test]
	public void CalculateDemeritPoints_SpeedIsNull_ThrowAgumentNullException()
	{
		var calculator = new DemeritPointsCalculator();
		Assert.That(() => calculator.CalculateDemeritPoints(null), Throws.Exception.TypeOf<ArgumentNullException>());
	}
	
	[Test]
	[TestCase(-1)]
	[TestCase(301)]
	public void CalculateDemeritPoints_SpeedIsOutOfRange_ThrowArgumentOutOfRangeException(int speed)
	{
		var calculator = new DemeritPointsCalculator();
		Assert.That(() => calculator.CalculateDemeritPoints(speed), Throws.Exception.TypeOf<ArgumentOutOfRangeException>());
	}

	[Test]
	[TestCase(0, 0)]
	[TestCase(64, 0)]
	[TestCase(65, 0)]
	[TestCase(70, 1)]
	[TestCase(75, 2)]
	public void CalculateDemeritPoints_WhenCalled_ReturnDemeritPoints(int speed, int demeritPoints)
	{
		var calculator = new DemeritPointsCalculator();
		var points = calculator.CalculateDemeritPoints(speed);
		Assert.That(points, Is.EqualTo(demeritPoints));
	}
}
```

## Stack

```cs
// Methods to test
public class Stack<T>
{
	private readonly List<T> _list = new List<T>();
	public int Count => _list.Count();

	public void Push(T obj)
	{
		if (obj is null)
		{
			throw new ArgumentNullException();
		}

		_list.Add(obj);
	}

	public T Pop()
	{
		if (_list.Count == 0)
		{
			throw new InvalidOperationException();
		}

		var itemToRemoveIndex = _list.Count - 1;
		var itemToRemove = _list[itemToRemoveIndex];

		_list.RemoveAt(itemToRemoveIndex);

		return itemToRemove;
	}

	public T Peek()
	{
		if (_list.Count == 0)
		{
			throw new InvalidOperationException();
		}

		return _list[_list.Count - 1];
	}
}

// Test methods
[TestFixture]
public class StackTests
{
	#PUSH
	[Test]
	public void Push_ArgIsNull_ThrowArgNullException()
	{
		var stack = new Stack<string>();
		Assert.That(() => stack.Push(null), Throws.Exception.TypeOf<ArgumentNullException>());
	}
	
	[Test]
	public void Push_ValidArg_AddObjToStack()
	{
		var stack = new Stack<string>();
		stack.Push("a");
		Assert.That(stack.Count, Is.EqualTo(1));
	}

	#COUNT
	[Test]
	public void Count_EmptyStack_ReturnZero()
	{
		var stack = new Stack<string>();
		Assert.That(stack.Count, Is.EqualTo(0));
	}

	#POP
	[Test]
	public void Pop_EmptyStack_ThrowInvalidOperationException()
	{
		var stack = new Stack<string>();
		Assert.That(() => stack.Pop(), Throws.Exception.TypeOf<InvalidOperationException>());
	}
	
	[Test]
	public void Pop_StackWithFewObjs_ReturnObjOnTop()
	{
		var stack = new Stack<string>();
		stack.Push("a");
		stack.Push("b");
		stack.Push("c");

		var poppedObj = stack.Pop();

		Assert.That(stack.Count, Is.EqualTo(2));
		Assert.That(poppedObj, "c");
	}

	#PEEK
	[Test]
	public void Peek_EmptyStack_ThrowInvalidOperationException(()
	{
		var stack = new Stack<string>();
		Assert.That(() => stack.Peek(), Throws.Exception.TypeOf<InvalidOperationException>());
	}

	[Test]
	public void Peek_StackWithObjs_ReturnObjTopOfStack(()
	{
		var stack = new Stack<string>();
		stack.Push("a");
		stack.Push("b");
		stack.Push("c");

		var peekedObj = stack.Peek();
		
		Assert.That(peekedObj, "c");
	}
	
	[Test]
	public void Peek_StackWithObjs_DoesNotRemoveObjTopOfStack()
	{
		var stack = new Stack<string>();
		stack.Push("a");
		stack.Push("b");
		stack.Push("c");

		stack.Peek();
		
		Assert.That(stack.Count, Is.EqualTo(3));
	}
}
```