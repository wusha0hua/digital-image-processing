function varargout = slider_demo(varargin)
% SLIDER_DEMO MATLAB code for slider_demo.fig
%      SLIDER_DEMO, by itself, creates a new SLIDER_DEMO or raises the existing
%      singleton*.
%
%      H = SLIDER_DEMO returns the handle to a new SLIDER_DEMO or the handle to
%      the existing singleton*.
%
%      SLIDER_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in SLIDER_DEMO.M with the given input arguments.
%
%      SLIDER_DEMO('Property','Value',...) creates a new SLIDER_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before slider_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to slider_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help slider_demo

% Last Modified by GUIDE v2.5 06-Nov-2015 17:17:31

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @slider_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @slider_demo_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before slider_demo is made visible.
function slider_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to slider_demo (see VARARGIN)

% Choose default command line output for slider_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes slider_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = slider_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on slider movement.
function my_slider_Callback(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider
value = get(hObject, 'Value');
set(handles.my_static_text, 'String', sprintf('%3.0f', value));


% --- Executes during object creation, after setting all properties.
function my_slider_CreateFcn(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
