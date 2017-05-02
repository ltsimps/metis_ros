#!/usr/bin/env python

#The following modules need to import before handling gstreamer API's

import gobject
import sys
import pygst
import rospy
from std_msgs.msg import String
pygst.require('0.10')
gobject.threads_init()
import gst

#Module to handle keyboard interrupt signal
import signal

#Keyboard signal handling routine
def signal_handle(signal, frame):
  print "You pressed Ctrl+C"
  sys.exit(0)


#Implementation of Speech recognition class
class Speech_Recog(object):
  pub = " "
  #Initializing gstreamer pipeline and pocket sphinx element
  def __init__(self):
    self.init_gst()
    self.pub = rospy.Publisher('voice_chatter', String, queue_size=10)
    rospy.init_node('voice', anonymous=True)

  #This function will initialize gstreamer pipeline
  def init_gst(self):
    #The following code create a gstreamer pipeline with pipeline description. The required descriptors needed for the code is given as parameters.
          self.pipeline = gst.parse_launch('gconfaudiosrc !audioconvert ! audioresample '
                     + '! vader name=vad auto-threshold=true '
                     + '! pocketsphinx name=asr ! fakesink')
    #Accessing pocket sphinx element from gstreamer pipeline
          asr = self.pipeline.get_by_name('asr')
    #Connecting to asr_result function when a speech to text conversion is completed
          asr.connect('result', self.asr_result)

      #User can mention lm and dict for accurate detection
      #asr.set_property('lm', '/home/user/mylanguagemodel.lm')
      #asr.set_property('dict','/home/user/mylanguagemodel.dic')

    #This option will set all options are configured well and can start recognition
          asr.set_property('configured', True)
    
    #Pausing the GStreamer pipeline at first.
          self.pipeline.set_state(gst.STATE_PAUSED)

      #Definition of asr_result
      #TODO:Modify to make it a publisher
  def asr_result(self, asr, text, uttid):
      #Printing the detected text
      print "Detected Text=>    ",text
      hello_str = "hello world " 
      #self.pub.publish(hello_str)
      self.pub.publish(text)
      '''   
      pub = rospy.Publisher('voice_chatter', String, queue_size=10)
      rospy.init_node('voice', anonymous=True)
      rate = rospy.Rate(1)
      while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        rospy.logininfo(hello_str)
        pub.publish(hello_str)
        rate.sleep()
      '''
 
    #This function will start/stop Speech recognition operation
  def start_recognition(self):
      #VADER - Voice Activity DEtectoR, which helps when the speech start and when its ends. Creating VADER object and set the property silent to False, so no speech will detected until key press
      vader = self.pipeline.get_by_name('vad')
      vader.set_property('silent', False)
      #Waiting for a key press to start recognition
      #raw_input("Press any key to start recognition:>")
      #Start playing the pipeline
      self.pipeline.set_state(gst.STATE_PLAYING)

      #Waiting for stopping the recognition
      raw_input("Press any key to stop recognition:>")
      vader = self.pipeline.get_by_name('vad')
      #Setting silent property of VADER to True
      vader.set_property('silent', True)
      #Pausing GStreamer pipeline
      self.pipeline.set_state(gst.STATE_PAUSED)

  def talk(self):
      #app_object = Speech_Recog()
      #Assign keyboard interrupt handler
      #signal.signal(signal.SIGINT, signal_handle)
      #pub = rospy.Publisher('voice_chatter', String, queue_size=10)
      #rospy.init_node('voice', anonymous=True)
      rate = rospy.Rate(1)
      #while not rospy.is_shutdown():
      #while not rospy.is_shutdown():
      #hello_str = "hello world " 
        #rospy.logininfo(hello_str)
      print("in while loop")
      #pub.publish(hello_str)
        #rate.sleep()
        #while True:
        #rospy.spin()
        #Calling Speech recognition routine
      self.start_recognition()

    
if __name__ == "__main__":

  #Creating an object of Speech_Recog() class
  app_object = Speech_Recog()

  #Assign keyboard interrupt handler
  #signal.signal(signal.SIGINT, signal_handle)
  
  print("in while loop")
  app_object.talk() 
  
  #while True:
    #talker()
    #Calling Speech recognition routine
    #app_object.start_recognition()
