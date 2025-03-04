# Types of tests

## Unit test

- Test a unit of an app **without its external dependencies**
- Used to handle edge cases

## Integration test

- Test the application **with its external dependencies**

## End-to-end test

- Used for happy path

# Test pyramid

![[Pasted image 20231126162206.png]]

- Favor unit tests > E2E tests
- Cover unit test gaps with integration tests
- Use E2E tests sparringly

---
# Test Driven Development

## Definition

- Write a failing test => Write the **simplest** code to make the test pass => Refactor if necessary

## Benefits

- Testable source code
- Full coverage by tests => Deploy with confidence
- Simpler implementation


---
# Unit testing

## Characteristics of good unit tests

- 1st class citizens => Priority
- Clean, readable and maintainable => Single responsibility
- No logic => **NO** If/else/foreach
- Isolated
- Not too specific/general
## What to test and not to

- Not to
	- Language features
	- 3rd-party code

## Naming and organizing tests

- Num of tests >= Num of execution paths
- `[MethodName]_[Scenario]_[ExpectedBehavior]`


---
# Untrustworthy testing

- NOT testing the right thing
- How to spot the buggy test: Change the output of the method to be tested => If the outcome is always passed, the test is bugged

```ad-important
Always write automated tests if possible. A great developer write tests.

```


---

