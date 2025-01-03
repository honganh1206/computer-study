# Reliability

- Typical expectations of our applications -> If all is working correctly, the
system is **reliable**:
   - Perform what the user expects
   - Tolerate the user making mistakes
   - Perform good enough for the required use case
   - Prevent any unauthorized access and abuse

- If not, the wrongs are called **faults**, and the system is **fault-tolerant/resilient** if it can cope with faults

- Faults != failures. A failure occurs when *the system stops providing its
services to the user*

- It makes sense to **deliberately introduce faults to our systems** as a way to
  ensure our systems are continuously tested and proved fault-tolerant.

- While we generally prefer tolerating faults, we still prefer prevention over cure due to *security matters*.

- Some of the faults/errors we are going to cover:
  - [[Hardware Faults]]
  - [[Software Errors]]
  - [[Human Errors]]
