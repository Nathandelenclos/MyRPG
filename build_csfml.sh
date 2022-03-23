#!/usr/bin/env bash

set -e

SFML_VERSION='2.2'
GLEW_VERSION='1.10.0'

get_file()
{
	local file_to_get="$1"
	local mirror="$2"
	local filename=$(echo $file_to_get | sed -e 's/.*\///')

	if ! [[ -f $filename ]]; then
		if [[ -z $mirror ]]; then
			wget "$file_to_get"
		else
			wget "$file_to_get" || wget "$mirror"
		fi
	else
		echo "-------- $filename already exists locally, skipping..."
	fi

	extract_archive $filename
}

extract_archive()
{
	local file_to_extract="$1"
	echo "extracting $file_to_extract..."
	tar -xf $file_to_extract
}

cd /tmp
get_file "https://"{www,mirror2}".sfml-dev.org/files/CSFML-$SFML_VERSION-linux-gcc-64-bit.tar.bz2"
get_file "https://"{www,mirror2}".sfml-dev.org/files/SFML-$SFML_VERSION-linux-gcc-64-bit.tar.gz"
get_file "https://sourceforge.net/projects/glew/files/glew/$GLEW_VERSION/glew-$GLEW_VERSION.tgz"

sudo apt install libx11-dev libxmu-dev libxi-dev libgl-dev libopenal-dev
cd /tmp/"glew-$GLEW_VERSION"
make

sudo rm -rfv /usr/local/include/{SFML,GL} /usr/local/lib/lib{*sfml*,GLEW*}
sudo cp -vr /tmp/{"CSFML-$SFML_VERSION","SFML-$SFML_VERSION","glew-$GLEW_VERSION"}/{include,lib} /usr/local
sudo rm -v /usr/local/lib/libcsfml*".$SFML_VERSION" # Avoid ldconfig warning on identical files with different filenames (/sbin/ldconfig.real: /usr/local/lib/libcsfml-xxx.so.2.2 is not a symbolic link)
sudo ldconfig

echo -e "\n\n"
echo "CSFML $SFML_VERSION has been installed"
echo "Please remember to add -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system in your Makefile"
echo
echo "2017 - Paul Laffitte - Epitech Montpellier Promo 2021"