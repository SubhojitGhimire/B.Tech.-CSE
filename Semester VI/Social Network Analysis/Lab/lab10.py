import networkx as nx
from bokeh.io import show
import ndlib.models.ModelConfig as mc
import ndlib.models.epidemics as ep
from ndlib.viz.bokeh.DiffusionTrend import DiffusionTrend

def SImodel (graph):
    print ("SI model")
    SI = ep.SIModel (graph)
    cfg = mc.Configuration ()
    cfg.add_model_parameter ('beta', 0.01)
    cfg.add_model_parameter ("percentage_infected", 0.05)
    SI.set_initial_status (cfg)
    iterations = SI.iteration_bunch (200, node_status = True)
    trends = SI.build_trends (iterations)
    viz = DiffusionTrend (SI, trends)
    show (viz.plot (width = 1000), new = "tab")

def SIRmodel (graph):
    print ("SIR model")
    SIR = ep.SIRModel (graph)
    config = mc.Configuration ()
    config.add_model_parameter ('beta', 0.001)
    config.add_model_parameter ('gamma', 0.01)
    config.add_model_parameter ('percentage_infected', 0.05)
    SIR.set_initial_status (config)
    iterations = SIR.iteration_bunch (200, node_status = True)
    trends = SIR.build_trends (iterations)
    viz = DiffusionTrend (SIR, trends)
    show (viz.plot (width = 1000), new = "tab")

def SISmodel (graph):
    print ("SIS model")
    SIS = ep.SISModel (graph)
    config = mc.Configuration ()
    config.add_model_parameter ('beta', 0.01)
    config.add_model_parameter ('lambda', 0.005)
    config.add_model_parameter ('fraction_infected', 0.05)
    SIS.set_initial_status (config)
    iterations = SIS.iteration_bunch (200, node_status = True)
    trends = SIS.build_trends (iterations)
    viz = DiffusionTrend (SIS, trends)
    show (viz.plot (width = 1000), new = "tab")

# NOTE: Sometimes, it may so happen that SI model gets overwritten by either SIR model or SIS model in output.
# In such cases, simply comment SISmodel (graph) and SIRmodel (graph) and run models individually.

print ("Karate Club")
graph = nx.read_gml ("karate.gml")
SImodel (graph)
SIRmodel (graph)
SISmodel (graph)

# print ("Football Club")
# graph = nx.read_gml ("football.gml")
# SImodel (graph)
# SIRmodel (graph)
# SISmodel (graph)

# print ("Dolphin Network")
# graph = nx.read_gml ("dolphins.gml")
# SImodel (graph)
# SISmodel (graph)
# SIRmodel (graph)

# print ("Albert Barabasi Network")
# graph = nx.barabasi_albert_graph (100, 15)
# SImodel (graph)
# SISmodel (graph)
# SIRmodel (graph)