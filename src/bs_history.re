module History = {
  type t;
  module Location = {
    type t;
    external pathname : t => string = "" [@@bs.get];
    external search : t => string = "" [@@bs.get];
    external hash : t => string = "" [@@bs.get];
    external key : t => option string = "" [@@bs.get];
  };
  module Action = {
    type t;
  };
  external length : t => int = "" [@@bs.get];
  external action : t => Action.t = "" [@@bs.get];
  external location : t => Location.t = "" [@@bs.get];
  external listen : t => Location.t => Action.t => unit => unit = "" [@@bs.send];
  /* TODO: state typing */
  module State = {
    type t;
  };
  external push : t => string => list State.t => unit = "" [@@bs.send];
  external replace : t => string => list State.t => unit = "" [@@bs.send];
  external go : t => int => unit = "" [@@bs.send];
  external goBack : t => unit = "" [@@bs.send];
  external goForward : t => unit = "" [@@bs.send];
};

type getUserConfirmation = (string, bool) => unit;

type browserHistoryOpt = {
  basename: string,
  forceRefresh: bool,
  keyLength: int,
  getUserConfirmation
};

external createBrowserHistory : browserHistoryOpt => History.t = "" [@@bs.module];

type memoryHistoryOpt = {initialEntries: list string, initialIndex: int, keyLength: int};

external createMemoryHistory : memoryHistoryOpt => History.t = "" [@@bs.module];

type hashHistoryOpt = {basename: string, hashType: string, getUserConfirmation};

external createHashHistory : hashHistoryOpt => History.t = "" [@@bs.module];
