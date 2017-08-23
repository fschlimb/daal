/* file: kmeans_init_batch.h */
/*******************************************************************************
* Copyright 2014-2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of the interface for initializing the K-Means algorithm
//  in the batch processing mode
//--
*/

#ifndef __KMEANS_INIT_BATCH_H__
#define __KMEANS_INIT_BATCH_H__

#include "algorithms/algorithm.h"
#include "data_management/data/numeric_table.h"
#include "services/daal_defines.h"
#include "algorithms/kmeans/kmeans_init_types.h"

namespace daal
{
namespace algorithms
{
namespace kmeans
{
namespace init
{

namespace interface1
{
/**
 * @defgroup kmeans_init_batch Batch
 * @ingroup kmeans_init
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__KMEANS__INIT__BATCHCONTAINER"></a>
 * \brief Provides methods to run implementations of initialization of the K-Means algorithm.
 *        This class is associated with the daal::algorithms::kmeans::init::Batch class
 *        and supports the method of computing initial clusters for the K-Means algorithm in the batch processing mode.
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of initial clusters for the K-Means algorithm, double or float
 * \tparam method           Method of computing initial clusters for the algorithm, \ref daal::algorithms::kmeans::init::Method
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class DAAL_EXPORT BatchContainer : public daal::algorithms::AnalysisContainerIface<batch>
{
public:
    /**
     * Constructs a container for initializing the K-Means algorithm with a specified environment
     * in the batch processing mode
     * \param[in] daalEnv   Environment object
     */
    BatchContainer(daal::services::Environment::env *daalEnv);
    /** Default destructor */
    virtual ~BatchContainer();
    /**
     * Computes initial values for the K-Means algorithm in the batch processing mode
     */
    virtual void compute() DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__KMEANS__INIT__BATCH"></a>
 * \brief Computes initial clusters for the K-Means algorithm in the batch processing mode
 * \n<a href="DAAL-REF-KMEANS-ALGORITHM">K-Means algorithm initialization description and usage models</a>
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of initial clusters for the K-Means algorithm, double or float
 * \tparam method           Method of computing initial clusters for the algorithm, \ref Method
 *
 * \par Enumerations
 *      - \ref Method   Methods of computing initial clusters for the K-Means algorithm
 *      - \ref InputId  Identifiers of input objects for computing initial clusters for the K-Means algorithm
 *      - \ref ResultId Identifiers of results of computing initial clusters for the K-Means algorithm
 */
template<typename algorithmFPType = double, Method method = defaultDense>
class DAAL_EXPORT Batch : public daal::algorithms::Analysis<batch>
{
public:
    /**
     *  Main constructor
     *  \param[in] nClusters   Number of clusters
     */
    Batch(size_t nClusters) : parameter(nClusters)
    {
        initialize();
    }

    /**
     * Constructs an algorithm that computes initial clusters for the K-Means algorithm
     * by copying input objects and parameters of another algorithm
     * \param[in] other An algorithm to be used as the source to initialize the input objects
     *                  and parameters of the algorithm
     */
    Batch(const Batch<algorithmFPType, method> &other) : parameter(other.parameter)
    {
        initialize();
        input.set(data, other.input.get(data));
    }

    /**
    * Returns the method of the algorithm
    * \return Method of the algorithm
    */
    virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

    /**
     * Returns the structure that contains the results of computing initial clusters for the K-Means algorithm
     * \return Structure that contains the results of computing initial clusters for the K-Means algorithm
     */
    services::SharedPtr<Result> getResult()
    {
        return _result;
    }

    /**
     * Registers user-allocated memory to store the results of computing initial clusters for the K-Means algorithm
     * \param[in] result  Structure to store the results of computing initial clusters for the K-Means algorithm
     */
    void setResult(const services::SharedPtr<Result>& result)
    {
        DAAL_CHECK(result, ErrorNullResult)
        _result = result;
        _res = _result.get();
    }

    /**
     * Returns a pointer to the newly allocated algorithm that computes initial clusters for the K-Means algorithm
     * with a copy of input objects and parameters of this algorithm
     * \return Pointer to the newly allocated algorithm
     */
    services::SharedPtr<Batch<algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Batch<algorithmFPType, method> >(cloneImpl());
    }

protected:
    virtual Batch<algorithmFPType, method> * cloneImpl() const DAAL_C11_OVERRIDE
    {
        return new Batch<algorithmFPType, method>(*this);
    }

    virtual void allocateResult() DAAL_C11_OVERRIDE
    {
        _result = services::SharedPtr<Result>(new Result());
        size_t nFeatures = input.getNumberOfFeatures();
        _result->allocate<algorithmFPType>(_in, _par, (int) method);
        _res = _result.get();
    }

    void initialize()
    {
        Analysis<batch>::_ac = new __DAAL_ALGORITHM_CONTAINER(batch, BatchContainer, algorithmFPType, method)(&_env);
        _in  = &input;
        _par = &parameter;
    }

public:
    Input input;            /*!< %Input data structure */
    Parameter parameter;    /*!< K-Means parameters structure */

private:
    services::SharedPtr<Result> _result;
};
/** @} */
} // namespace interface1
using interface1::BatchContainer;
using interface1::Batch;
} // namespace daal::algorithms::kmeans::init
} // namespace daal::algorithms::kmeans
} // namespace daal::algorithms
} // namespace daal
#endif
