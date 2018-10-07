open ReDomSuite;

let mSpan = Document.getElementById(ReDom.document, "span");

let spanFrame = Js.Option.getExn(mSpan)
    |> IFrame.cast;

Js.log(Js.Option.isSome(spanFrame));

let iFrame = Document.getElementById(ReDom.document, "iframe")
  |> Js.Option.getExn
  |> IFrame.cast;

switch iFrame {
    | None => Js.log("None")
    | Some(iFrame) =>
        Js.log(Element.tagName(iFrame));
        Js.log(IFrame.contentWindow(iFrame))
};

let span = mSpan |> Js.Option.getExn;
Js.log(Element.tagName(span));

Js.log(ReDom.encodeUri("http://blah.com/?ok=s p a c e"));
Js.log(ReDom.encodeUriComponent("http://blah.com/?ok=s p a c e"));

Window.alert("alrt", ReDom.window);
Window.prompt(~message="prmtpt", ReDom.window) |> Js.log2("!");
