open ReDomTypes

include AbstractElement.Impl({
  type t = textarea
  let tagName = "TEXTAREA"
})

@get external value: t => string = ""
