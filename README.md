# fs --> file Search
 fs a file searching program which uses kmpSearching algorithm algong with recursion to find your file :)

Usage :
  fs [file to serach...] [options...] [argsOfOptions...]
  fs --help : gives you details about program
  fs [file] : in default search files on current directory.
  fs [file] -d [...dir] : this will search for the similar file at give dir.
  fs [file] -d [...dir] -s : this will turn on strict mode.
    in strict mode the program dont ignore the . or hidden folders and other folders like { "node_module", "vendor", "tmp","coverage",    "target", "build"}
NOTE : turning on strict mode may cause the program to slow down.

NOTE: This program dont uses multy threading for now.
