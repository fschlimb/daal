/* file: LocallyConnected2dLayerDataId.java */
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
 * @ingroup locallyconnected2d
 * @{
 */
package com.intel.daal.algorithms.neural_networks.layers.locallyconnected2d;

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__LOCALLYCONNECTED2D__LOCALLYCONNECTED2DLAYERDATAID"></a>
 * \brief Identifiers of input objects for the backward 2D locally connected layer and results for the forward 2D locally connected layer
 */
public final class LocallyConnected2dLayerDataId {
    /** @private */
    static {
        System.loadLibrary("JavaAPI");
    }

    private int _value;

    /**
     * Constructs the result object identifier using the provided value
     * @param value     Value of the input object identifier
     */
    public LocallyConnected2dLayerDataId(int value) {
        _value = value;
    }

    /**
     * Returns the value corresponding to the result identifier
     * @return Value corresponding to the result identifier
     */
    public int getValue() {
        return _value;
    }

    private static final int auxDataId = 0;
    private static final int auxWeightsId = 1;

    public static final LocallyConnected2dLayerDataId auxData    = new LocallyConnected2dLayerDataId(auxDataId);    /*!< Data processed at the forward stage of the layer */
    public static final LocallyConnected2dLayerDataId auxWeights = new LocallyConnected2dLayerDataId(auxWeightsId); /*!< Weights of the 2D locally connected layer */
}
/** @} */
