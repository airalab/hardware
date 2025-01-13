{ pkgs ? import <nixpkgs> {} }:
let
in
  pkgs.mkShell {
    buildInputs = [
      pkgs.platformio
      pkgs.esptool
      pkgs.python312Packages.pip
      pkgs.python312Packages.zopfli
      pkgs.python312Packages.wheel
      # optional: needed as a programmer i.e. for esp32
      # pkgs.avrdude
    ];
    shellHook = ''
export PLATFORMIO_CORE_DIR=$PWD/.platformio
'';
}
