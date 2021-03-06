% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/conic_solvers.R
\docType{class}
\name{CVXOPT-class}
\alias{CVXOPT-class}
\alias{mip_capable,CVXOPT-method}
\alias{status_map,CVXOPT-method}
\alias{name,CVXOPT-method}
\alias{import_solver,CVXOPT-method}
\alias{accepts,CVXOPT,Problem-method}
\alias{perform,CVXOPT,Problem-method}
\alias{solve_via_data,CVXOPT-method}
\title{An interface for the CVXOPT solver.}
\usage{
\S4method{mip_capable}{CVXOPT}(solver)

\S4method{status_map}{CVXOPT}(solver, status)

\S4method{name}{CVXOPT}(x)

\S4method{import_solver}{CVXOPT}(solver)

\S4method{accepts}{CVXOPT,Problem}(object, problem)

\S4method{perform}{CVXOPT,Problem}(object, problem)

\S4method{solve_via_data}{CVXOPT}(object, data, warm_start, verbose, solver_opts, solver_cache)
}
\arguments{
\item{solver, object, x}{A \linkS4class{CVXOPT} object.}

\item{status}{A status code returned by the solver.}

\item{problem}{A \linkS4class{Problem} object.}

\item{data}{Data generated via an apply call.}

\item{warm_start}{A boolean of whether to warm start the solver.}

\item{verbose}{A boolean of whether to enable solver verbosity.}

\item{solver_opts}{A list of Solver specific options}

\item{solver_cache}{Cache for the solver.}
}
\description{
An interface for the CVXOPT solver.
}
\section{Methods (by generic)}{
\itemize{
\item \code{mip_capable}: Can the solver handle mixed-integer programs?

\item \code{status_map}: Converts status returned by the CVXOPT solver to its respective CVXPY status.

\item \code{name}: Returns the name of the solver.

\item \code{import_solver}: Imports the solver.

\item \code{accepts}: Can CVXOPT solve the problem?

\item \code{perform}: Returns a new problem and data for inverting the new solution.

\item \code{solve_via_data}: Solve a problem represented by data returned from apply.
}}

