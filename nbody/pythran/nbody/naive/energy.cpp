#define BOOST_SIMD_NO_STRICT_ALIASING 1
#include <pythonic/core.hpp>
#include <pythonic/python/core.hpp>
#include <pythonic/types/bool.hpp>
#include <pythonic/types/int.hpp>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <pythonic/include/types/numpy_texpr.hpp>
#include <pythonic/include/types/float.hpp>
#include <pythonic/include/types/ndarray.hpp>
#include <pythonic/types/ndarray.hpp>
#include <pythonic/types/float.hpp>
#include <pythonic/types/numpy_texpr.hpp>
#include <pythonic/include/__builtin__/None.hpp>
#include <pythonic/include/math/sqrt.hpp>
#include <pythonic/include/__builtin__/getattr.hpp>
#include <pythonic/include/numpy/square.hpp>
#include <pythonic/include/__builtin__/list.hpp>
#include <pythonic/include/__builtin__/xrange.hpp>
#include <pythonic/include/operator_/div.hpp>
#include <pythonic/include/__builtin__/str.hpp>
#include <pythonic/__builtin__/None.hpp>
#include <pythonic/math/sqrt.hpp>
#include <pythonic/__builtin__/getattr.hpp>
#include <pythonic/numpy/square.hpp>
#include <pythonic/__builtin__/list.hpp>
#include <pythonic/__builtin__/xrange.hpp>
#include <pythonic/operator_/div.hpp>
#include <pythonic/__builtin__/str.hpp>
namespace __pythran_energy
{
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  struct force
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename pythonic::assignable<double>::type __type0;
      typedef double __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type2;
      typedef decltype((std::declval<__type1>() * std::declval<__type2>())) __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type4;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type4>::type>::type __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type6>::type>::type __type7;
      typedef typename pythonic::assignable<decltype((std::declval<__type5>() - std::declval<__type7>()))>::type __type8;
      typedef decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::square{})>::type>::type>()(std::declval<__type8>())) __type9;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type4>::type>::type __type10;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type6>::type>::type __type11;
      typedef typename pythonic::assignable<decltype((std::declval<__type10>() - std::declval<__type11>()))>::type __type12;
      typedef decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::square{})>::type>::type>()(std::declval<__type12>())) __type13;
      typedef decltype((std::declval<__type9>() + std::declval<__type13>())) __type14;
      typedef decltype((std::declval<__type14>() + std::declval<__type1>())) __type16;
      typedef typename pythonic::assignable<decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::math::functor::sqrt{})>::type>::type>()(std::declval<__type16>()))>::type __type17;
      typedef decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::square{})>::type>::type>()(std::declval<__type17>())) __type18;
      typedef decltype((std::declval<__type18>() * std::declval<__type17>())) __type19;
      typedef typename pythonic::assignable<decltype((pythonic::operator_::div(std::declval<__type3>(), std::declval<__type19>())))>::type __type20;
      typedef typename __combined<__type0,__type20>::type __type21;
      typedef decltype((std::declval<__type21>() * std::declval<__type8>())) __type22;
      typedef pythonic::types::list<__type22> __type23;
      typedef decltype((std::declval<__type21>() * std::declval<__type12>())) __type25;
      typedef pythonic::types::list<__type25> __type26;
      typedef typename pythonic::returnable<typename __combined<__type23,__type26>::type>::type result_type;
    }
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0 const & p1, argument_type1 const & p2, argument_type2 const & m2) const
    ;
  }  ;
  struct eps
  {
    typedef void callable;
    typedef void pure;
    struct type
    {
      typedef typename pythonic::returnable<double>::type result_type;
    }  ;
    typename type::result_type operator()() const;
    ;
  }  ;
  struct gamma_si
  {
    typedef void callable;
    typedef void pure;
    struct type
    {
      typedef typename pythonic::returnable<double>::type result_type;
    }  ;
    typename type::result_type operator()() const;
    ;
  }  ;
  struct compute_energy
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef double __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type2;
      typedef decltype(pythonic::__builtin__::getattr<pythonic::types::attr::SHAPE>(std::declval<typename __combined<__type0,__type2>::type>())) __type3;
      typedef typename pythonic::lazy<typename std::tuple_element<0,typename std::remove_reference<__type3>::type>::type>::type __type4;
      typedef decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::__builtin__::functor::xrange{})>::type>::type>()(std::declval<__type4>())) __type5;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type5>::type::iterator>::value_type>::type __type6;
      typedef pythonic::types::contiguous_slice __type7;
      typedef decltype(std::declval<__type1>()(std::declval<__type6>(), std::declval<__type7>())) __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type13;
      typedef decltype(std::declval<__type13>()[std::declval<__type6>()]) __type14;
      typedef decltype(std::declval<force>()(std::declval<__type8>(), std::declval<__type8>(), std::declval<__type14>())) __type15;
      typedef __type0 __ptype0;
      typedef __type15 __ptype1;
      typedef typename pythonic::returnable<pythonic::types::none_type>::type result_type;
    }
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0 const & mass, argument_type1 const & particles, argument_type2&& energy) const
    ;
  }  ;
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename force::type<argument_type0, argument_type1, argument_type2>::result_type force::operator()(argument_type0 const & p1, argument_type1 const & p2, argument_type2 const & m2) const
  {
    typedef typename pythonic::assignable<double>::type __type0;
    typedef double __type1;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type2;
    typedef decltype((std::declval<__type1>() * std::declval<__type2>())) __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type4;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type4>::type>::type __type5;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type6>::type>::type __type7;
    typedef typename pythonic::assignable<decltype((std::declval<__type5>() - std::declval<__type7>()))>::type __type8;
    typedef decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::square{})>::type>::type>()(std::declval<__type8>())) __type9;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type4>::type>::type __type10;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type6>::type>::type __type11;
    typedef typename pythonic::assignable<decltype((std::declval<__type10>() - std::declval<__type11>()))>::type __type12;
    typedef decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::square{})>::type>::type>()(std::declval<__type12>())) __type13;
    typedef decltype((std::declval<__type9>() + std::declval<__type13>())) __type14;
    typedef decltype((std::declval<__type14>() + std::declval<__type1>())) __type16;
    typedef typename pythonic::assignable<decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::math::functor::sqrt{})>::type>::type>()(std::declval<__type16>()))>::type __type17;
    typedef decltype(std::declval<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::square{})>::type>::type>()(std::declval<__type17>())) __type18;
    typedef decltype((std::declval<__type18>() * std::declval<__type17>())) __type19;
    typedef typename pythonic::assignable<decltype((pythonic::operator_::div(std::declval<__type3>(), std::declval<__type19>())))>::type __type20;
    typename pythonic::assignable<decltype((std::get<0>(p2) - std::get<0>(p1)))>::type dx = (std::get<0>(p2) - std::get<0>(p1));
    typename pythonic::assignable<decltype((std::get<1>(p2) - std::get<1>(p1)))>::type dy = (std::get<1>(p2) - std::get<1>(p1));
    typename pythonic::assignable<decltype(pythonic::math::functor::sqrt{}(((pythonic::numpy::functor::square{}(dx) + pythonic::numpy::functor::square{}(dy)) + 0.010000000000000002)))>::type dist = pythonic::math::functor::sqrt{}(((pythonic::numpy::functor::square{}(dx) + pythonic::numpy::functor::square{}(dy)) + 0.010000000000000002));
    typename pythonic::assignable<typename __combined<__type0,__type20>::type>::type F = 0.0;
    if (dist > 0L)
    {
      F = (pythonic::operator_::div((6.67408e-11 * m2), (pythonic::numpy::functor::square{}(dist) * dist)));
    }
    return typename pythonic::assignable<pythonic::types::list<typename __combined<typename std::remove_cv<typename std::remove_reference<decltype((F * dx))>::type>::type,typename std::remove_cv<typename std::remove_reference<decltype((F * dy))>::type>::type>::type>>::type({(F * dx), (F * dy)});
  }
  typename eps::type::result_type eps::operator()() const
  {
    {
      static typename eps::type::result_type tmp_global = 0.010000000000000002;
      return tmp_global;
    }
  }
  typename gamma_si::type::result_type gamma_si::operator()() const
  {
    {
      static typename gamma_si::type::result_type tmp_global = 6.67408e-11;
      return tmp_global;
    }
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename compute_energy::type<argument_type0, argument_type1, argument_type2>::result_type compute_energy::operator()(argument_type0 const & mass, argument_type1 const & particles, argument_type2&& energy) const
  {
    energy[pythonic::types::contiguous_slice(pythonic::__builtin__::None,pythonic::__builtin__::None)] = 0.0;
    typename pythonic::lazy<decltype(std::get<0>(pythonic::__builtin__::getattr<pythonic::types::attr::SHAPE>(energy)))>::type N = std::get<0>(pythonic::__builtin__::getattr<pythonic::types::attr::SHAPE>(energy));
    {
      long  __target1 = N;
      for (long  i = 0L; i < __target1; i += 1L)
      {
        {
          long  __target2 = N;
          for (long  j = 0L; j < __target2; j += 1L)
          {
            if (i != j)
            {
              ;
              energy(i,pythonic::types::contiguous_slice(2L,pythonic::__builtin__::None)) += force()(particles(i,pythonic::types::contiguous_slice(pythonic::__builtin__::None,2L)), particles(j,pythonic::types::contiguous_slice(pythonic::__builtin__::None,2L)), mass.fast(j));
            }
          }
        }
      }
    }
    energy(pythonic::types::contiguous_slice(pythonic::__builtin__::None,pythonic::__builtin__::None),pythonic::types::contiguous_slice(pythonic::__builtin__::None,2L)) = particles(pythonic::types::contiguous_slice(pythonic::__builtin__::None,pythonic::__builtin__::None),pythonic::types::contiguous_slice(2L,pythonic::__builtin__::None));
    return pythonic::__builtin__::None;
  }
}
#include <pythonic/python/exception_handler.hpp>
typename __pythran_energy::compute_energy::type<pythonic::types::ndarray<double,1>, pythonic::types::ndarray<double,2>, pythonic::types::ndarray<double,2>>::result_type compute_energy0(pythonic::types::ndarray<double,1> a0, pythonic::types::ndarray<double,2> a1, pythonic::types::ndarray<double,2> a2)
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_energy::compute_energy()(a0, a1, a2);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_energy::compute_energy::type<pythonic::types::ndarray<double,1>, pythonic::types::ndarray<double,2>, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>::result_type compute_energy1(pythonic::types::ndarray<double,1> a0, pythonic::types::ndarray<double,2> a1, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>> a2)
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_energy::compute_energy()(a0, a1, a2);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_energy::compute_energy::type<pythonic::types::ndarray<double,1>, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>, pythonic::types::ndarray<double,2>>::result_type compute_energy2(pythonic::types::ndarray<double,1> a0, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>> a1, pythonic::types::ndarray<double,2> a2)
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_energy::compute_energy()(a0, a1, a2);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_energy::compute_energy::type<pythonic::types::ndarray<double,1>, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>::result_type compute_energy3(pythonic::types::ndarray<double,1> a0, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>> a1, pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>> a2)
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_energy::compute_energy()(a0, a1, a2);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}

static PyObject *
__pythran_wrap_compute_energy0(PyObject *self, PyObject *args)
{
    PyObject* args_obj[3+1];
    if(! PyArg_ParseTuple(args, "OOO", &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,1>>(args_obj[0]) and is_convertible<pythonic::types::ndarray<double,2>>(args_obj[1]) and is_convertible<pythonic::types::ndarray<double,2>>(args_obj[2]))
        return to_python(compute_energy0(from_python<pythonic::types::ndarray<double,1>>(args_obj[0]), from_python<pythonic::types::ndarray<double,2>>(args_obj[1]), from_python<pythonic::types::ndarray<double,2>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_compute_energy1(PyObject *self, PyObject *args)
{
    PyObject* args_obj[3+1];
    if(! PyArg_ParseTuple(args, "OOO", &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,1>>(args_obj[0]) and is_convertible<pythonic::types::ndarray<double,2>>(args_obj[1]) and is_convertible<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[2]))
        return to_python(compute_energy1(from_python<pythonic::types::ndarray<double,1>>(args_obj[0]), from_python<pythonic::types::ndarray<double,2>>(args_obj[1]), from_python<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_compute_energy2(PyObject *self, PyObject *args)
{
    PyObject* args_obj[3+1];
    if(! PyArg_ParseTuple(args, "OOO", &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,1>>(args_obj[0]) and is_convertible<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[1]) and is_convertible<pythonic::types::ndarray<double,2>>(args_obj[2]))
        return to_python(compute_energy2(from_python<pythonic::types::ndarray<double,1>>(args_obj[0]), from_python<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,2>>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_compute_energy3(PyObject *self, PyObject *args)
{
    PyObject* args_obj[3+1];
    if(! PyArg_ParseTuple(args, "OOO", &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,1>>(args_obj[0]) and is_convertible<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[1]) and is_convertible<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[2]))
        return to_python(compute_energy3(from_python<pythonic::types::ndarray<double,1>>(args_obj[0]), from_python<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[1]), from_python<pythonic::types::numpy_texpr<pythonic::types::ndarray<double,2>>>(args_obj[2])));
    else {
        return nullptr;
    }
}

            static PyObject *
            __pythran_wrapall_compute_energy(PyObject *self, PyObject *args)
            {
                return pythonic::handle_python_exception([self, args]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_compute_energy0(self, args))
    return obj;


if(PyObject* obj = __pythran_wrap_compute_energy1(self, args))
    return obj;


if(PyObject* obj = __pythran_wrap_compute_energy2(self, args))
    return obj;


if(PyObject* obj = __pythran_wrap_compute_energy3(self, args))
    return obj;

                PyErr_SetString(PyExc_TypeError,
                "Invalid argument type for pythranized function `compute_energy'.\n"
                "Candidates are:\n   compute_energy(ndarray<double,1>,ndarray<double,2>,ndarray<double,2>)\n   compute_energy(ndarray<double,1>,ndarray<double,2>,numpy_texpr<ndarray<double,2>>)\n   compute_energy(ndarray<double,1>,numpy_texpr<ndarray<double,2>>,ndarray<double,2>)\n   compute_energy(ndarray<double,1>,numpy_texpr<ndarray<double,2>>,numpy_texpr<ndarray<double,2>>)\n"
                );
                return nullptr;
                });
            }

static PyMethodDef Methods[] = {
    {
    "compute_energy",
    __pythran_wrapall_compute_energy,
    METH_VARARGS,
    "Supported prototypes:\n    - compute_energy(float[], float[][], float[][])\n    - compute_energy(float[], float[][], float[][].T)\n    - compute_energy(float[], float[][].T, float[][])\n    - compute_energy(float[], float[][].T, float[][].T)\n"},
    {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
  static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "energy",            /* m_name */
    "",         /* m_doc */
    -1,                  /* m_size */
    Methods,             /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#define PYTHRAN_RETURN return theModule
#define PYTHRAN_MODULE_INIT(s) PyInit_##s
#else
#define PYTHRAN_RETURN return
#define PYTHRAN_MODULE_INIT(s) init##s
#endif
PyMODINIT_FUNC
PYTHRAN_MODULE_INIT(energy)(void)
__attribute__ ((visibility("default")))
__attribute__ ((externally_visible));
PyMODINIT_FUNC
PYTHRAN_MODULE_INIT(energy)(void) {
    #ifdef PYTHONIC_TYPES_NDARRAY_HPP
        import_array()
    #endif
    #if PY_MAJOR_VERSION >= 3
    PyObject* theModule = PyModule_Create(&moduledef);
    #else
    PyObject* theModule = Py_InitModule3("energy",
                                         Methods,
                                         ""
    );
    #endif
    if(not theModule)
        PYTHRAN_RETURN;
    PyObject * theDoc = Py_BuildValue("(sss)",
                                      "0.8.0",
                                      "2017-05-23 20:57:55.424044",
                                      "2f5392bf8125d5cf279da49510f60c5e8613f1296c58ef1c941a34101ca00ff2");
    if(not theDoc)
        PYTHRAN_RETURN;
    PyModule_AddObject(theModule,
                       "__pythran__",
                       theDoc);

    PYTHRAN_RETURN;
}