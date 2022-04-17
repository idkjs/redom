type t

@val external location: t = ""
let wrap = (f, ~location=location) => f(location)
let wrapU = (f, ~location=location, ()) => f(location)

@get external protocol: t => string = ""
@get external host: t => string = ""
@get external hostname: t => string = ""
@get external port: t => string = ""
@get external pathname: t => string = ""
@get external search: t => string = ""
@get external hash: t => string = ""
@get external origin: t => string = ""

@get external username: t => Js.nullable<string> = ""
@get external password: t => Js.nullable<string> = ""
let username = l => username(l) |> Js.Nullable.toOption
let password = l => password(l) |> Js.Nullable.toOption

@get external href: t => string = ""
@set external setHref: (t, string) => unit = "href"

let protocol = wrapU(protocol)
let host = wrapU(host)
let hostname = wrapU(hostname)
let port = wrapU(port)
let pathname = wrapU(pathname)
let search = wrapU(search)
let hash = wrapU(hash)
let username = wrapU(username)
let password = wrapU(password)
let origin = wrapU(origin)
let href = wrapU(href)
let setHref = wrap(setHref)
