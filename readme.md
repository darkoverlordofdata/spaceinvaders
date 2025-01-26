# hello-world

port of mwbryant/wasm4-space-invaders simple space invaders clone to c23

## wip

currently adding artemis too see if an ecs fits in 64k

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

bash publish

add to docs/index.html header element
```html
	<!-- Meta Tags for Progressive Web App -->
	<meta name="apple-mobile-web-app-status-bar" content="#aa7700">
	<meta name="theme-color" content="black">

	<!-- Meta Tags for BlueSky -->
  <meta property="og:title" content="Space Invaders"/>
  <meta property="og:type" content="website"/> 
  <meta property="og:locale" content="en_US">
  <meta property="og:url" content="https://darkoverlordofdata.com/spaceinvaders/"/>
  <meta property="og:description" content="Space Invaders Game"/>
  <meta property="og:image" content="https://darkoverlordofdata.com/spaceinvaders/thumbnail.png"/>

	<!-- Link to the Manifest File -->
	<link rel="manifest" href="manifest.json">
	<link rel="icon" href="./favicon.ico"/>    
```

For more info about setting up WASM-4, see the [quickstart guide](https://wasm4.org/docs/getting-started/setup?code-lang=c#quickstart).

## Links

- [Documentation](https://wasm4.org/docs): Learn more about WASM-4.
- [Snake Tutorial](https://wasm4.org/docs/tutorials/snake/goal): Learn how to build a complete game
  with a step-by-step tutorial.


## artemis 

artemis ecs in c

### wip

- &#x2611; phase i     files and define basic types
- &#x2611; phase ii    interface
- &#x2610; phase iii   implementation stubs
- &#x2610; phase iv    implementation code



