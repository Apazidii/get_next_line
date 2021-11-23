for f in *;do
mv "$f" "${f%.*}_bonus.${f##*.}"
done