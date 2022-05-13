import networkx as nx
from bokeh.io import show
import ndlib.models.ModelConfig as mc
import ndlib.models.epidemics as ep
from ndlib.viz.bokeh.DiffusionTrend import DiffusionTrend

def SImodel (GG, title):
    print ("\nSI MODEL -> ", title)
    SI = ep.SIModel (GG)
    # CONFIGURATION
    cfg = mc.Configuration ()
    cfg.add_model_parameter ('beta', 0.01)
    cfg.add_model_parameter ("percentage_infected", 0.05)
    SI.set_initial_status (cfg)
    # SIMULATION
    iterations = SI.iteration_bunch (200, node_status = True)
    trends = SI.build_trends (iterations)
    # VISUALISATION
    viz = DiffusionTrend (SI, trends)
    show (viz.plot (width = 1000), new = "tab")

def SIRmodel (GG, title):
    print ("\nSIR MODEL -> ", title)
    SIR = ep.SIRModel (GG)
    # CONFIGURATION
    config = mc.Configuration ()
    config.add_model_parameter ('beta', 0.001)
    config.add_model_parameter ('gamma', 0.01)
    config.add_model_parameter ('percentage_infected', 0.05)
    SIR.set_initial_status (config)
    # SIMULATION
    iterations = SIR.iteration_bunch (200, node_status = True)
    trends = SIR.build_trends (iterations)
    viz = DiffusionTrend (SIR, trends)
    show (viz.plot (width = 1000), new = "tab")

def SISmodel (GG, title):
    print ("\nSIS MODEL -> ", title)
    SIS = ep.SISModel (GG)
    # CONFIGURATION
    config = mc.Configuration ()
    config.add_model_parameter ('beta', 0.01)
    config.add_model_parameter ('lambda', 0.005)
    config.add_model_parameter ('fraction_infected', 0.05)
    SIS.set_initial_status (config)
    # SIMULATION
    iterations = SIS.iteration_bunch (200, node_status = True)
    trends = SIS.build_trends (iterations)
    viz = DiffusionTrend (SIS, trends)
    show (viz.plot (width = 1000), new = "tab")

# LOADING KARATE CLUB GRAPH
GG = nx.read_gml ("karate.gml")
SImodel (GG, "KARATE CLUB")
SIRmodel (GG, "KARATE CLUB")
SISmodel (GG, "KARATE CLUB")

# # LOADING FOOTBALL CLUB
# GG = nx.read_gml ("football.gml")
# SImodel (GG, "FOOTBALL CLUB")
# SIRmodel (GG, "FOOTBALL CLUB")
# SISmodel (GG, "FOOTBALL CLUB")

# # LOADING DOLPHIN NETWORK
# GG = nx.read_gml ("dolphins.gml")
# SImodel (GG, "DOLPHIN NETWORK")
# SISmodel (GG, "DOLPHIN NETWORK")
# SIRmodel (GG, "DOLPHIN NETWORK")

# # LOADING BARABASI-ALBERT NETWORK
# GG = nx.barabasi_albert_graph (100, 15)
# SImodel (GG, "BARABASI-ALBERT NETWORK")
# SISmodel (GG, "BARABASI-ALBERT NETWORK")
# SIRmodel (GG, "BARABASI-ALBERT NETWORK")