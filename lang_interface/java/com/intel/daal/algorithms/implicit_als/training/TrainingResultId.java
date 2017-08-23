/* file: TrainingResultId.java */
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

/**
 * @ingroup implicit_als_training
 * @{
 */
package com.intel.daal.algorithms.implicit_als.training;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__IMPLICIT_ALS__TRAINING__TRAININGRESULTID"></a>
 * @brief Available identifiers of the results of the implicit ALS training algorithm
 */
public final class TrainingResultId {
    private int _value;

    static {
        System.loadLibrary("JavaAPI");
    }

    /**
     * Constructs the input object identifier using the provided value
     * @param value     Value of the input object identifier
     */
    public TrainingResultId(int value) {
        _value = value;
    }

    /**
     * Returns the value of the input object identifier
     * @return    Value of the input object identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int modelId = 0;

    /** Implicit ALS model */
    public static final TrainingResultId model = new TrainingResultId(modelId);
}
/** @} */
