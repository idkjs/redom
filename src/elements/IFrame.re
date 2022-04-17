open ReDomTypes;

include AbstractElement.Impl({
    type t = iframe;
    let tagName = "IFRAME";
});

[@get] external contentWindow : t => Dom.window = "";
