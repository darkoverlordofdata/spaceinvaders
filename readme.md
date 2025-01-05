# hello-world

port of mwbryant/wasm4-space-invaders simple space invaders clone to c23

## Building

Build the cart by running:

```shell
bear -- make
```

Then run it with:

```shell
w4 run build/cart.wasm
```

publish

```
mkdir -p docs
w4 bundle build/cart.wasm --title "Space Invaders" --html docs/index.html
```


For more info about setting up WASM-4, see the [quickstart guide](https://wasm4.org/docs/getting-started/setup?code-lang=c#quickstart).

## Links

- [Documentation](https://wasm4.org/docs): Learn more about WASM-4.
- [Snake Tutorial](https://wasm4.org/docs/tutorials/snake/goal): Learn how to build a complete game
  with a step-by-step tutorial.
- [GitHub](https://github.com/aduros/wasm4): Submit an issue or PR. Contributions are welcome!
