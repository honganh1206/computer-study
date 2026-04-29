`.*\\.txt` means zero or more of any character ending with `.txt`. The `\.` signals the literal dot, and the backslash itself must be backslash-escaped.

We can use `[]` as an alternative to `\\`

```rust
let re = Regex::new(".*[.]csv").unwrap();
assert!(re.is_match("foo.csv"));
assert!(re.is_match(".csv.foo"));
```

Use `$` to match the end of a string and `^` to match the beginning of the string

```rust
let re = Regex::new(".*[.]csv$").unwrap();
assert!(re.is_match("foo.csv"));
assert!(!re.is_match(".csv.foo"));
```