//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

module Node
{
    parameters:
        int node_id;
    gates:
        input in;
        output out;
    submodules:
        appLayerObject: App_layer{appId=node_id;};
        dataLayerObject: Data_layer{dataId=node_id;};
        physicalLayerObject: Physical_layer{physicalId=node_id;};
    connections:
        appLayerObject.toData --> dataLayerObject.fromApp;
        appLayerObject.fromData <-- dataLayerObject.toApp;
        dataLayerObject.toPhysical --> physicalLayerObject.fromData;
        dataLayerObject.fromPhysical <-- physicalLayerObject.toData;
        in --> physicalLayerObject.fromNode;
        physicalLayerObject.toNode --> out;
}
