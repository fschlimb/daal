/* file: SpatialAveragePooling2dMethod.java */
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
 * @ingroup spatial_average_pooling2d
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.spatial_average_pooling2d;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__SPATIAL_AVERAGE_POOLING2D__SPATIALAVERAGEPOOLING2DMETHOD"></a>
 * @brief Available methods for the two-dimensional spatial average pooling layer
 */
public final class SpatialAveragePooling2dMethod {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    private int _value;

    /**
     * Constructs the method object using the provided value
     * @param value     Value of the method object identifier
     */
    public SpatialAveragePooling2dMethod(int value) {
        _value = value;
    }

    /**
     * Returns the value of the method identifier
     * @return Value of the method identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int DefaultMethodValue = 0;

    public static final SpatialAveragePooling2dMethod defaultDense = new SpatialAveragePooling2dMethod(DefaultMethodValue); /*!< Default method */
}
/** @} */
