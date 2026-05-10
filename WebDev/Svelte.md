$state == useState() (raw value)

$derived == useMemo() (computed value + cache expensive computation)

$effect == useEffect() (side effect when values change)

Svelte compiles your code into JS + no virtual DOM

$bindable: Two -way binding, child and parent can read/write value >< In React parent must pass value and handlle updates

# 🧠 Svelte Runes Cheatsheet (with React Comparison)

## 📦 Core Idea
Svelte uses **runes** to make reactivity explicit:

- `$state` → reactive state
- `$derived` → computed values
- `$effect` → side effects
- `$bindable` → two-way binding
- `$props()` → access component props

---

# ⚙️ 1. State

## Svelte
```js
let count = $state(0);

function increment() {
  count++;
}

// React

const [count, setCount] = useState(0);

function increment() {
  setCount(count + 1);
}
```

---

# 🔄 2. Derived (Computed Values)

## Svelte

```js
let count = $state(2);
let double = $derived(count * 2);
```

## React

```js
const double = useMemo(() => count * 2, [count]);
```

✅ Auto-tracks dependencies in Svelte  
❌ Manual dependency array in React

---

# 🔥 3. Effects (Side Effects)

## Svelte

```js
$effect(() => {
  console.log(count);
});
```

## React

```js
useEffect(() => {
  console.log(count);
}, [count]);
```

---

# 🔗 4. Bindable (Two-way binding)

## Child (Svelte)

```js
let { value = $bindable() } = $props();
```

## Parent

```html
<Child bind:value={text} />
```

```js
let text = $state("Hello");
```

## React Equivalent

```js
function Child({ value, onChange }) {
  return <input value={value} onChange={e => onChange(e.target.value)} />;
}
```

---

# 📥 5. Props

## Svelte

```js
let { message, count = 0 } = $props();
```

## Usage

```html
<Child message="Hello 👋" count={5} />
```

---

# 🌍 6. Unicode in Props

```html
<Child message="Xin chào 👋" />
```

```js
let { message } = $props();
```

✅ Works out of the box (UTF-8)

---

# ⚠️ Unicode Gotchas

## Length issue

```js
"😀".length // 2
```

Fix:

```js
[..."😀"].length // 1
```

## Equality issue

```js
"é" === "é" // false
```

Fix:

```js
a.normalize() === b.normalize()
```

---

# 🧩 7. Combining Runes

```js
let count = $state(1);
let doubled = $derived(count * 2);

$effect(() => {
  console.log(doubled);
});
```

---

# 🧠 Mental Model

|Concept|Svelte|React|
|---|---|---|
|State|`$state`|`useState`|
|Computed|`$derived`|`useMemo`|
|Effects|`$effect`|`useEffect`|
|Two-way|`$bindable`|props + callbacks|
|Props|`$props()`|function args|

---

# 🔥 Key Differences

## Svelte

- Compile-time reactivity
- No dependency arrays
- Direct mutation (`count++`)
- Less boilerplate

## React

- Runtime re-renders
- Dependency arrays required
- Immutable updates
- More control, more complexity

---

# 🚀 Common Patterns

## Reactive UI

```js
let name = $state("Anh");
let greeting = $derived(`Hello ${name}`);
```

## Form Input

```html
<input bind:value={name} />
```

## Effect Example

```js
$effect(() => {
  console.log("Updated:", name);
});
```

---

# ⚡ Rules of Thumb

- Use `$state` for anything that changes
- Use `$derived` instead of recalculating manually
- Use `$effect` only for side effects
- Use `$bindable` for shared state between components
- Avoid overusing two-way binding

---

# 🧪 Debug Tips

- If UI doesn’t update → missing `$state` or `$derived`
- If effect runs too often → check dependencies (React) or logic
- If Unicode breaks → check UTF-8 encoding
