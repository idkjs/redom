open ReDomTypes;

include AbstractElement.Impl({
    type nonrec t = img;
    let tagName = "IMG";
});

[@get] external src : t => string = "";
[@set] external setSrc : t => string => unit = "src";
let setSrc = (loc, elem) => {
    setSrc(elem, loc);
    elem;
};

let blank =
    create()
    |> setSrc("data:image/gif;base64,R0lGODlhAQABAAAAACH5BAEKAAEALAAAAAABAAEAAAICTAEAOw==");
