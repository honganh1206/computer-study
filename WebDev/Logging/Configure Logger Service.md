# DI, IoC and Logger Service Testing
## Dependency Injection

```ad-summary
title: Summary of DI
Rather than instantiating an object explicitly in a class every time we need it, we can **instantiate it once and then send it to the class**.

```
- Constructor injection - Inject dependencies via the constructor
- Classes that manage and provide dependencies are called Inversion of Control containers (IoC) - The control of the dependencies is inverted from the consumer (service classes) to the injector (`ServiceExtension` class/main program that handles dependencies)