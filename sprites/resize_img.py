#! /bin/env python3

from PIL import Image
from os import path
import argparse

# check args
parser = argparse.ArgumentParser(description='Resize single image and save it with new name.')
parser.add_argument('img_path', type=str, help='Path to image')
parser.add_argument('width', type=int, help='New width')
parser.add_argument('height', type=int, help='New height')
parser.add_argument('-o', '--new_name', type=str, help='New image name')
args = parser.parse_args()

image = Image.open(args.img_path)
image = image.resize((args.width, args.height))

directory, name = path.split(path.abspath(args.img_path))
if args.new_name:
    new_name = path.join(directory, args.new_name)
else:
    name, ext = path.splitext(name)
    name = name + f'({args.width}x{args.height})' + ext
    new_name = path.join(directory, name)

image.save(new_name)
print(new_name)