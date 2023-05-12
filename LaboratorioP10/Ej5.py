def variable_length(**kwargs):
    print (f"{len(kwargs)} data structures and their operations:")
    for title, name in kwargs.items():
      print (f"\t{titlr}->{name}")

    variable_length(stack="pop, push", queue="enqueue, dequeueu")