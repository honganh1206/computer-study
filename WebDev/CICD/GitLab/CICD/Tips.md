# Tips - For ideas/solutions collected when debugging

- If the image is set as default image for the whole pipeline, the include cannot be used in pipelines that define an own default image.
- Each `default` keyword is copied to every job that doesn’t already have it defined. If the job already has a keyword defined, that default is not used.