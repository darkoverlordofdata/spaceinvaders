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

publish:

```
mkdir -p docs
w4 bundle build/cart.wasm --title "Space Invaders" --html docs/index.html
cp ./thumbnail.png docs/thumbnail.png
```
add to docs/index.html header element
```html
  <meta property="og:title" content="Space Invaders"/>
  <meta property="og:type" content="website"/> 
  <meta property="og:locale" content="en_US">
  <meta property="og:url" content="https://darkoverlordofdata.com/spaceinvaders/"/>
  <meta property="og:description" content="Space Invaders Game"/>
  <meta property="og:image" content="https://darkoverlordofdata.com/spaceinvaders/thumbnail.png"/>
```

For more info about setting up WASM-4, see the [quickstart guide](https://wasm4.org/docs/getting-started/setup?code-lang=c#quickstart).

## Links

- [Documentation](https://wasm4.org/docs): Learn more about WASM-4.
- [Snake Tutorial](https://wasm4.org/docs/tutorials/snake/goal): Learn how to build a complete game
  with a step-by-step tutorial.


