File type and permissions are displayed using *a string of 10 characters* like `drwxr-xr-x`, and *each letter indicates a specific piece of information* like `d` for directory and `l` for llinks.

Three permissions for reading, writing and executing are displayed as on or off with three bits. Thus there are $2^3$ combinations of choices.

Fixed permissions bits 4 (`100`) for Read, 2  (`010`) for Write and 1 (`001`) for Execute.

```css
/*Permission 775 - Read + write + execute for user and group
but everyone can only read + execute */
421 (7) - rwx - User
421 (7) - rwx - Group
401 (5) - r-x - Other
```