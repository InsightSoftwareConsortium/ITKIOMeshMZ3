#!/usr/bin/env python

# Copyright NumFOCUS
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#         https://www.apache.org/licenses/LICENSE-2.0.txt
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.

__doc__ = """ 
Example of how to read and write a Mesh in MZ3 format

Any mesh file format supported by ITK can be read and written using the
script below. The file format is determined by the file extension.

If compression is enabled, the file will be written in a compressed format.
For MZ3 files, GZip compression is used.
"""

import argparse

import itk

parser = argparse.ArgumentParser(description="Read and write a Mesh in MZ3 format")
parser.add_argument("input_mesh")
parser.add_argument("output_mesh")
parser.add_argument("-c", "--compression", action="store_true", help="Enable compression")
args = parser.parse_args()

mesh = itk.meshread(args.input_mesh)
itk.meshwrite(mesh, args.output_mesh, compression=args.compression)
