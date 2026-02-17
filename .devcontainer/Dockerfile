FROM mcr.microsoft.com/devcontainers/cpp:noble

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Optionally install the cmake for vcpkg
COPY .devcontainer/reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
    chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}"; \
    fi && \
    rm -f /tmp/reinstall-cmake.sh

RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends \
    autoconf \
    autoconf-archive \
    automake \
    clang-format \
    fzf \
    lcov \
    libtool \
    python3 \
    python3-pip \
    ruby-bundler \
    ruby-dev \
    shellcheck \
    shfmt && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /workspaces && \
    chown -R vscode:vscode /workspaces

RUN git config --system init.defaultBranch main && \
    git config --system alias.cof "!git branch -a | fzf | xargs git checkout"

# Install online-judge-verify-helper to verify
RUN python3 -m pip install --break-system-packages --no-cache-dir online-judge-verify-helper 

# Install gtest for testing
RUN su vscode -c "${VCPKG_ROOT}/vcpkg install gtest"

# Install nektos/act for testing GitHub Actions locally
RUN curl --proto '=https' --tlsv1.2 -sSf https://raw.githubusercontent.com/nektos/act/master/install.sh | sudo bash
