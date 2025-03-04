# GitLab CICD

## [Caching](https://docs.gitlab.com/ee/ci/caching/)

## Cache vs Artifacts


| Cache                                                                             | Artifacts                                                                      |
| --------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ |
| - Defined per job with the `cache` keyword                                        | - Defined per job                                                              |
| - Subsequent pipelines can use the cache                                          | Subsequent **jobs** in the later stages of the same pipeline can use artifacts |
| - If identical dependencies => Subsequent jobs in the same pipeline can use cache | - Different projects cannot share artifacts                                    |
| - Different projects do not share cache                                           | Artifacts have adjustable expiration time                                      |
|                                                                                   | Use dependencies to control which jobs fetch the artifacts                     |
## Good caching practices

- Tag your runners
- Use runners available for a particular project
- Use a key that fits your workflow

## Cache availability

- Using docker runner → `/var/lib/docker/volumes/<volume-id>/_data/<user>/<project>/<cache-key>/cache.zip`.

To use the same cache for all branches:

1. On the left sidebar, select **Search or go to** and find your project.
2. Select **Settings > CI/CD**.
3. Expand **General pipelines**.
4. Clear the **Use separate caches for protected branches** checkbox.
5. Select **Save changes**.