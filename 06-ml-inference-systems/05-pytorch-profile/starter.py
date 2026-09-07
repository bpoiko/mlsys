import torch


def build_workload():
    """TODO: return a small deterministic inference workload and fixed inputs."""
    raise NotImplementedError


def verify(reference, candidate):
    """TODO: define the correctness comparison before performance changes."""
    raise NotImplementedError


def main():
    # TODO: warm up, measure repeated samples, then add a scheduled profiler trace.
    pass


if __name__ == "__main__":
    main()
