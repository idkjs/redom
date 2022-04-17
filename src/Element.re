type t('a) = ReDomTypes.element('a);

external fromDom: Dom.element => t(unit) = "%identity";
// https://forum.rescript-lang.org/t/the-guide-to-migrate-away-from-bs-send-pipe/1593
[@bs.send.pipe: t(_)] external appendChild: t('a) => t('a) = "";
let appendChild = (~parent, ~child) => appendChild(child, parent);

[@bs.send.pipe: t(_)] external focus: unit = "";

[@get] external innerHtml: t('a) => unit = "innerHTML";
[@set] external setInnerHtml: t('a) => string => unit = "innerHTML";
let setInnerHtml = (html, elem) => {
    setInnerHtml(elem, html);
    elem;
};

[@bs.send.pipe: t(_)] external onDrag:
    ([@as "drag"] _, DragEvent.t => unit) => unit = "addEventListener";
[@bs.send.pipe: t(_)] external onDragEnd:
    ([@as "dragend"] _, DragEndEvent.t => unit) => unit = "addEventListener";

[@get] external scrollWidth: t(_) => int = "";
[@get] external scrollHeight: t(_) => int = "";
[@get] external scrollLeft: t(_) => int = "";
[@get] external scrollTop: t(_) => int = "";
[@get] external tagName: t(_) => string = "";
