



# now

Learning to use the [`Drom`](https://ocamlpro.github.io/drom/) build system for ocam/reasonml projects.

- This is a port of for starting [now.ml](https://github.com/spencerwi/now.ml) project to [reasonml](https://reasonml.github.io/) using `drom`.

It took nothing at all to compile with reason. Apparently, `drom` is aware of reason syntax files. This is a really nice addition to the options for building with reason/ocaml and might be my go to option to start a project. Thanks to the folks at [`OCamlPro`](https://github.com/OCamlPro?type=source)

# Examples
```sh
$ now minus 1 hour

$ now minus 5 days
```

# From Scratch

```sh
[I] ➜ opam install drom
[I] ➜ drom new now
[I] ➜ drom build -y
[I] ➜ ./now
2021-01-10T13:18:18
```

# Installing on your system

```sh
[I] ➜ drom install
Warning: drom is not correctly installed in this switch:
/Users/mandalarian/Downloads/now/_opam/share/drom/skeletons is missing
Warning: could not load skeletons from share/drom/skeletons/project
Warning: could not load skeletons from share/drom/skeletons/package
drom: Entering directory '/Users/mandalarian/Downloads/now'
In opam switch /Users/mandalarian/Downloads/now/_opam
Warning: could not load licenses from share/drom/licenses
Calling git submodule update --init --recursive
Calling opam exec -- dune build @install
Done: 65/71 (jobs: 1)Calling opam uninstall -y now
[ERROR] now unknown package
Calling opam uninstall -y now_lib
[ERROR] now_lib unknown package
Calling opam pin -y --no-action -k path .
This will pin the following packages: now_lib, now. Continue?
[Y/n] y
Package now_lib does not exist, create as a NEW package?
[Y/n] y
[now_lib.~dev] synchronised from file:///Users/mandalarian/Downloads/now
[WARNING] Failed checks on now_lib package definition from
          source at file:///Users/mandalarian/Downloads/now:
  warning 35: Missing field 'homepage'
  warning 36: Missing field 'bug-reports'
now_lib is now pinned to file:///Users/mandalarian/Downloads/now (version 0.1.0)
Package now does not exist, create as a NEW package? [Y/n] y
[now.~dev] synchronised from file:///Users/mandalarian/Downloads/now
[WARNING] Failed checks on now package definition from source
          at file:///Users/mandalarian/Downloads/now:
  warning 35: Missing field 'homepage'
  warning 36: Missing field 'bug-reports'
now is now pinned to file:///Users/mandalarian/Downloads/now (version 0.1.0)
Calling opam install -y now now_lib

<><> Synchronising pinned packages ><><><><><><><><><><><>  🐫
[now.0.1.0] synchronised from file:///Users/mandalarian/Downloads/now
[now_lib.0.1.0] synchronised from file:///Users/mandalarian/Downloads/now

The following actions will be performed:
  ∗ install now_lib 0.1.0*
  ∗ install now     0.1.0*
===== ∗ 2 =====

<><> Processing actions <><><><><><><><><><><><><><><><><>  🐫
∗ installed now_lib.0.1.0
∗ installed now.0.1.0
Done.

Installation OK

# open a new terminal and run `which now`
# now is installed at /Users/mandalarian/.local/bin/now
now on  reason [✘!?] via ⬢ v14.4.0
 [I] ➜
 [I] ➜ which now
/Users/mandalarian/.local/bin/now

 [I] ➜ now
2021-01-10T13:28:27

/ 
 [I] ➜ now minus 1 hour
2021-01-10T12:28:28

/ 
 [I] ➜ now minus 5 days
2021-01-05T13:28:39
```

[repo](https://github.com/idkjs/now)
