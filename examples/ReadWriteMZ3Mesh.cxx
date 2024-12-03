/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkCommand.h"
#include "itkMeshFileReader.h"
#include "itkMeshFileWriter.h"
#include "itkMesh.h"


int main( int argc, char * argv[] )
{
  if( argc < 4 )
    {
    std::cerr << "Missing parameters." << std::endl;
    std::cerr << "Usage: " << argv[0]
      << " inputMesh"
      << " outputMesh"
      << " useCompression" << std::endl;
    return EXIT_FAILURE;
    }

  char * inputMeshFileName = argv[1];
  char * outputMeshFileName = argv[2];
  bool useCompression = std::stoi( argv[3] );

  constexpr unsigned int Dimension = 3;
  using PixelType = float;
  using MeshType = itk::Mesh< PixelType, Dimension >;

  // Read the mesh
  // Any mesh format supported by ITK can be used here, including MZ3.
  const auto mesh = itk::ReadMesh< MeshType >( inputMeshFileName );

  mesh->Print( std::cout );

  // Write the mesh
  // Any mesh format supported by ITK can be used here, including MZ3.
  // If useCompression is true, an MZ3 file includes GZip compression.
  itk::WriteMesh( mesh, outputMeshFileName, useCompression );

  return EXIT_SUCCESS;
}
