cmd_/home/tcwg-buildslave/workspace/tcwg-make-release/builder_arch/i386/label/tcwg-x86_64-build/target/arm-linux-gnueabi/_build/sysroots/arm-linux-gnueabi/usr/include/rdma/.install := /bin/bash scripts/headers_install.sh /home/tcwg-buildslave/workspace/tcwg-make-release/builder_arch/i386/label/tcwg-x86_64-build/target/arm-linux-gnueabi/_build/sysroots/arm-linux-gnueabi/usr/include/rdma ./include/uapi/rdma cxgb3-abi.h cxgb4-abi.h hns-abi.h ib_user_cm.h ib_user_mad.h ib_user_sa.h ib_user_verbs.h mlx4-abi.h mlx5-abi.h mthca-abi.h nes-abi.h ocrdma-abi.h qedr-abi.h rdma_netlink.h rdma_user_cm.h rdma_user_rxe.h vmw_pvrdma-abi.h; /bin/bash scripts/headers_install.sh /home/tcwg-buildslave/workspace/tcwg-make-release/builder_arch/i386/label/tcwg-x86_64-build/target/arm-linux-gnueabi/_build/sysroots/arm-linux-gnueabi/usr/include/rdma ./include/rdma ; /bin/bash scripts/headers_install.sh /home/tcwg-buildslave/workspace/tcwg-make-release/builder_arch/i386/label/tcwg-x86_64-build/target/arm-linux-gnueabi/_build/sysroots/arm-linux-gnueabi/usr/include/rdma ./include/generated/uapi/rdma ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/tcwg-buildslave/workspace/tcwg-make-release/builder_arch/i386/label/tcwg-x86_64-build/target/arm-linux-gnueabi/_build/sysroots/arm-linux-gnueabi/usr/include/rdma/$$F; done; touch /home/tcwg-buildslave/workspace/tcwg-make-release/builder_arch/i386/label/tcwg-x86_64-build/target/arm-linux-gnueabi/_build/sysroots/arm-linux-gnueabi/usr/include/rdma/.install
