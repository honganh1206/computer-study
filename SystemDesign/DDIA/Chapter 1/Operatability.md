---
id: Operatability
aliases:
  - Operatability
tags: []
---

# Operability

> Good operations can work around the limitations of bad software, but good software cannot run reliably with bad operations

A good operation team is responsible for

(Compare to my last project team)

- [x] Monitoring the health of the system and quickly restoring the service in case of bad state
- [x] Tracking down the cause of problems
- [!] Keeping software and platforms up to date
- [>] Keeping tabs on how different systems affect each other
- [!] Anticipating future problems
- [~] Establishing good practices and tools
- [!] Performing complex maintenance tasks
- [!] Maintaining the security of the system as configuration changes
- [~] Defining processes to make operation predictable
- [x] Preserving the organization's knowledge

Data systems can do various things to make routine tasks easy:

- [x] Providing visibility into the runtime behavior and internals of the system
- [~] Providing good support for automation and integration with standard tools
- [>] Avoid dependency on individual machines (allowing machines to be taken down for maintenance while the system keeps running)
- [>] Providing good documentation and easy-to-understand operational model ("If do X, Y will happen")
- [x] Providing good default behavior, but also giving administrators the freedom to override defaults when needed
- [!] Self-healing when appropriate, but giving administrators manual control when needed
- [>] Exhibiting predictable behavior, minimizing surprises
