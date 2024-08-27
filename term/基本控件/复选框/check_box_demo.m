function varargout = check_box_demo(varargin)
% CHECK_BOX_DEMO MATLAB code for check_box_demo.fig
%      CHECK_BOX_DEMO, by itself, creates a new CHECK_BOX_DEMO or raises the existing
%      singleton*.
%
%      H = CHECK_BOX_DEMO returns the handle to a new CHECK_BOX_DEMO or the handle to
%      the existing singleton*.
%
%      CHECK_BOX_DEMO('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CHECK_BOX_DEMO.M with the given input arguments.
%
%      CHECK_BOX_DEMO('Property','Value',...) creates a new CHECK_BOX_DEMO or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before check_box_demo_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to check_box_demo_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help check_box_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 10:50:56

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @check_box_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @check_box_demo_OutputFcn, ...
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


% --- Executes just before check_box_demo is made visible.
function check_box_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to check_box_demo (see VARARGIN)

% Choose default command line output for check_box_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes check_box_demo wait for user response (see UIRESUME)
% uiwait(handles.figure_main);


% --- Outputs from this function are returned to the command line.
function varargout = check_box_demo_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function my_edit_Callback(hObject, eventdata, handles)
% hObject    handle to my_edit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of my_edit as text
%        str2double(get(hObject,'String')) returns contents of my_edit as a double
str = get(hObject, 'string');
val = str2num(str);
if ~isempty(val) && (val >= 0 & val <= 1)
    set(handles.my_slider, 'value', val)
end


% --- Executes during object creation, after setting all properties.
function my_edit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to my_edit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function my_slider_Callback(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function my_slider_CreateFcn(hObject, eventdata, handles)
% hObject    handle to my_slider (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: slider controls usually have a light gray background.
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on button press in slide_permit.
function slide_permit_Callback(hObject, eventdata, handles)
% hObject    handle to slide_permit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of slide_permit
if get(hObject, 'value')
    set(handles.my_slider, 'Enable', 'on')
else
    set(handles.my_slider, 'Enable', 'off')
end
