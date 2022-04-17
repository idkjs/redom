type t;

[@new] external make: (~url: string) => (~base: string=?) => t = "URL";
let make = (~base=?, url) => make(~url, ~base?);

[@get] external hash: t => string = "hash";
[@get] external host: t => string = "host";
[@get] external hostname: t => string = "hostname";
[@get] external href: t => string = "href";
[@get] external password: t => string = "password";
[@get] external pathname: t => string = "pathname";
[@get] external port: t => string = "port";
[@get] external protocol: t => string = "protocol";
[@get] external search: t => string = "search";
[@get] external username: t => string = "username";

[@set] external setHash: t => string => unit = "hash";
[@set] external setHost: t => string => unit = "host";
[@set] external setHostname: t => string => unit = "hostname";
[@set] external setHref: t => string => unit = "href";
[@set] external setPassword: t => string => unit = "password";
[@set] external setPathname: t => string => unit = "pathname";
[@set] external setPort: t => string => unit = "port";
[@set] external setProtocol: t => string => unit = "protocol";
[@set] external setSearch: t => string => unit = "search";
[@set] external setUsername: t => string => unit = "username";

let immutable = (f) =>
    (v, url) => {
        let newUrl = href(url) |> make(_);
        f(newUrl, v);
        newUrl;
    };

let withHash = immutable(setHash);
let withHost = immutable(setHost);
let withHostname = immutable(setHostname);
let withHref = immutable(setHref);
let withPassword = immutable(setPassword);
let withPathname = immutable(setPathname);
let withPort = immutable(setPort);
let withProtocol = immutable(setProtocol);
let withSearch = immutable(setSearch);
let withUsername =  immutable(setUsername);

[@get] external origin: t => string = "hash";
