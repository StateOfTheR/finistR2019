## demo renv

## default lib
.libPaths()
nrow(installed.packages())
  
renv::init()

## new lib
.libPaths()
nrow(installed.packages())

## get status
renv::status()

## look at scripts and install missing packages
renv::dependencies()

## if the project is a package, dependencies skips all files except DESCRIPTION

## save state of packages
renv::snapshot()

## lockfile is the only file needed to restore same state
## use renv::restore()