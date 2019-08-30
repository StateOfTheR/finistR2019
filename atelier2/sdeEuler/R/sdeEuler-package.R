#' @keywords internal
"_PACKAGE"

# The following block is used by usethis to automatically manage
# roxygen namespace tags. Modify with care!
## usethis namespace: start
#' @useDynLib sdeEuler
#' @import Rcpp
## usethis namespace: end

NULL

Rcpp::loadModule("drift_rw_Module", TRUE)

