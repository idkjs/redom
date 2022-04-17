open ReDomTypes;

include AbstractElement.Impl({
    type t = input;
    let tagName = "INPUT";
});

[@get] external value : t => string = "";
