---
id: Configure Spark in Microsoft Fabric
aliases:
  - Configure Spark in Microsoft Fabric
tags: []
---

# Configure Spark in Microsoft Fabric

![[Pasted image 20250413160647.png]]

[[About Spark]]

## Starter Spark Pool

Automatically created for a workspace

Use pre-hydrated compute resources

Fast startup time

Consume Fabric capacity when in use

Auto scale based on increasing workload & dynamically allocate executors

Customize-able (Fabric sets the boundaries)

## Custom Spark Pool

Can be set as the default one

Compute resources provisioned on demand, but take longer to start

Consume less capacity, or data might require more computation, or we can divide processing to differ

NO support for CI/CD

## Environment

Can be deployed using CI/CD like other objects

Allow more Spark customization

One workspace can have multiple environments

Default environment can be defined for a workspace

## High Concurrency

Allow notebooks to share a same Spark sessions - Up to 5 notebooks

Can be used in data pipeline with Spark session tags

Sessions sharing conditions (same user, same Lakehouse, same Spark configuration)

## Spark Job Settings

Reserve maximum cores for active Spark jobs

Spark session timeout