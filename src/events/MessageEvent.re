open ReDomSharedTypes;

type t = Js.t {.
  data: Js.Json.t,
  origin: string,
  source: window
};