//    This file is part of cvxr

#ifdef _R_INTERFACE_
#include "cvxr.h"
#include "CVXcanon.hpp"

// Make a map out of an Rcpp List. Caller's responsibility
// to ensure proper names etc.
std::map<std::string, double>  makeMap(Rcpp::List L) {
  std::map<std::string, double> result;
  Rcpp::StringVector s = L.names();
  for (int i = 0; i < s.size(); i++) {
    result[Rcpp::as<std::string>(s[i])] = L[i];
  }
  return(result);
}

//' Get the \code{sparse} flag field for the LinOp object
//'
//' @param xp the LinOpVector Object XPtr
//' @param v the \code{id_to_col} named int vector in R with integer names
//' @return a XPtr to ProblemData Object
// [[Rcpp::export]]
SEXP build_matrix_0(SEXP xp, Rcpp::IntegerVector v) {
  // grab the object as a XPtr (smart pointer)
  Rcpp::XPtr<LinOpVector> ptrX(xp);
  std::map<int, int> id_to_col;
  Rcpp::StringVector s = v.names();
  for (int i = 0; i < s.size(); i++) {
    id_to_col[atoi(s[i])] = v[i];
  }
  Rcpp::Rcout << "Before Build Matrix" <<std::endl;
  //  ProblemData res = build_matrix(ptrX->linvec, id_to_col);
  //  Rcpp::Rcout << "After Build Matrix" <<std::endl;  
  //  Rcpp::XPtr<ProblemData> resPtr(&res, true);

  Rcpp::XPtr<ProblemData> resPtr(new ProblemData(), true);
  build_matrix_2(ptrX->linvec, id_to_col, resPtr);
  Rcpp::Rcout << "After constructing external ptr" <<std::endl;    
  return resPtr;
}

//' Get the \code{sparse} flag field for the LinOp object
//'
//' @param xp the LinOpVector Object XPtr
//' @param v1 the \code{id_to_col} named int vector in R with integer names
//' @param v2 the \code{constr_offsets} vector of offsets (an int vector in R)
//' @return a XPtr to ProblemData Object
// [[Rcpp::export]]
SEXP build_matrix_1(SEXP xp, Rcpp::IntegerVector v1, Rcpp::IntegerVector v2) {
  // grab the object as a XPtr (smart pointer)
  Rcpp::XPtr<LinOpVector> ptrX(xp);
  std::map<int, int> id_to_col;
  Rcpp::StringVector s = v1.names();
  for (int i = 0; i < s.size(); i++) {
    id_to_col[atoi(s[i])] = v1[i];
  }
  std::vector<int> constr_offsets;
  for (int i = 0; i < v2.size(); i++) {
    constr_offsets.push_back(v2[i]);
  }
  
  Rcpp::Rcout << "Before Build Matrix" <<std::endl;
  // ProblemData res = build_matrix(ptrX->linvec, id_to_col, constr_offsets);
  // Rcpp::Rcout << "After Build Matrix" <<std::endl;    
  // Rcpp::XPtr<ProblemData> resPtr(&res, true);
  Rcpp::XPtr<ProblemData> resPtr(new ProblemData(), true);
  build_matrix_3(ptrX->linvec, id_to_col, constr_offsets, resPtr);
  
  Rcpp::Rcout << "After constructing external ptr" <<std::endl;    
  return resPtr;
}

#endif
