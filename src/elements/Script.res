open ReDomTypes

include AbstractElement.Impl({
  type t = script
  let tagName = "SCRIPT"
})

@get external src: t => string = ""
@set external setSrc: (t, string) => unit = "src"
let setSrc = (loc, elem) => {
  setSrc(elem, loc)
  elem
}
