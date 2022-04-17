type t = Dom.window;

[@val] external window: t = "";
let wrap = (f) => (~window=window) => f(window);
let wrapU = (f) => (~window=window, ()) => f(window);

external asDict: t => Js.Dict.t(_) = "%identity";
let set = (~window=window, key, value) =>
    Js.Dict.set(asDict(window), key, value);

type listener = Js.Json.t => unit;

[@send] external alert: t => string => unit = "";
[@send] external close: t => unit = "";
[@send] external onLoad:
    (t, [@as "load"] _, LoadEvent.t => unit) => unit = "addEventListener";
[@send] external onMessage:
    (t, [@as "message"] _, listener) => unit = "addEventListener";
[@get] external opener: t => Js.Nullable.t(t) = "opener";
[@send] external open_: t => string => string => Js.null(t) = "open";
[@get] external parent: t => t = "";
[@send] external postMessage: (t, Js.Json.t, string) => unit = "";
[@send] external prompt:
    (t, ~message:string=?, ~default:string=?, unit) => Js.null(string) = "prompt";
[@send] external removeMessageListener:
    (t, [@as "message"] _, listener) => unit = "removeEventListener";

let alert = wrap(alert);
let close = wrapU(close);
let onLoad = wrap(onLoad);
let parent = wrapU(parent);
let postMessage = wrap(postMessage);

let onMessage = (~window=window, listener) => {
    let listener = (json) =>
        MessageEvent.t_decode(json)
        |> Belt.Result.getExn
        |> listener;

    onMessage(window, listener);
    listener;
};

let opener = (~window=window, ()) =>
    opener(window) |> Js.Nullable.toOption;

let open_ = (~window=window, ~name="__blank", url) =>
    open_(window, url, name)
    |> Js.Null.toOption;

let prompt = (~window=window, ~message=?, ~default=?, ()) =>
    prompt(window, ~message?, ~default?, ())
    |> Js.Null.toOption;

let removeMessageListener = (~window=window, listener) =>
    removeMessageListener(window, listener);
