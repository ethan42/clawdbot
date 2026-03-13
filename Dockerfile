FROM --platform=linux/i386 i386/debian as builder

RUN apt update && apt install -fy gcc make python3 git python3-pip sudo strace

RUN mkdir -p /workdir

WORKDIR /workdir

COPY clawdbot.c clawdbot.c

RUN git clone https://github.com/threadexio/evilcc && \
    cd evilcc && \
    make CFLAGS="-m32" ARCH=i386

 # Build clawdbot
 RUN /workdir/evilcc/evilcc \
    --personality-add ADDR_NO_RANDOMIZE \
    --drop-sugid prctl --setuid -1 --setgid -1 \
    -m32 \
    -o clawdbot clawdbot.c --verbose \
    -zexecstack -no-pie -fno-stack-protector

FROM --platform=linux/i386 i386/debian as production

RUN apt update && apt install -fy gcc make gdb python3 less file vim gosu checksec strace

RUN mkdir -p /workdir
WORKDIR /workdir

COPY --from=builder /workdir/clawdbot.c /workdir/clawdbot.c
COPY --from=builder /workdir/clawdbot /sbin/clawdbot

RUN chown root:root /sbin/clawdbot && chmod u+rws,g+rs,o+rx /sbin/clawdbot

RUN useradd -m -s /bin/bash bot

RUN chown bot:bot /workdir

WORKDIR /workdir

USER bot

CMD [ "clawdbot" ]
