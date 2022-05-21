{ pkgs }: {
	deps = [
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
    pkgs.gfortran10
    pkgs.python39Packages.pip
    pkgs.python38
	];
}