#递归查找并替换目录和文件的名称：
find . -depth -name '*foo*' -execdir bash -c 'for f; do mv -i "$f" "${f//foo/bar}"; done' bash {} +

find . -depth -name '*test*' -execdir bash -c 'for f; do mv -i "$f" "${f//test/mygood}"; done' bash {} +

find . -depth -name '*eos-vm-oc*' -execdir bash -c 'for f; do mv -i "$f" "${f//eos-vm-oc/taf-vm-oc}"; done' bash {} +
find . -depth -name '*eos-vm*' -execdir bash -c 'for f; do mv -i "$f" "${f//eos-vm/taf-vm}"; done' bash {} +
find . -depth -name '*eosio*' -execdir bash -c 'for f; do mv -i "$f" "${f//eosio/tafio}"; done' bash {} +